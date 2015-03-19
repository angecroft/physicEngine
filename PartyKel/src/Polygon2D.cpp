#include "PartyKel/Polygon2D.h"
#include <math.h>

namespace PartyKel {

Polygon2D::Polygon2D(std::vector<glm::vec2> points, glm::vec3 color, bool bIsInner) :
    m_points(points), m_color(color), m_bIsInner(bIsInner) {

}

Polygon2D Polygon2D::buildBox(glm::vec3 color, glm::vec2 position, float width, float height, bool isInner) {
    std::vector<glm::vec2> points;
    //point inférieur gauche
    points.push_back(position);
    //point inférieur droit
    points.push_back(glm::vec2 (position.x + width, position.y));
    //point supérieur droit
    points.push_back(glm::vec2 (position.x + width, position.y + height));
    //point supérieur gauche
    points.push_back(glm::vec2 (position.x, position.y + height));

   return Polygon2D(points, color, isInner);
}

Polygon2D Polygon2D::buildCircle(glm::vec3 color, glm::vec2 center, float radius, size_t discFactor, bool isInner) {
    std::vector<glm::vec2> points;
    double slice = 2 * M_PI / discFactor;
    for(int i=0; i<discFactor; ++i) {
        double angle = slice * i;
        float newX = center.x + radius * cos(angle);
        float newY = center.y + radius * sin(angle);
        points.push_back(glm::vec2(newX, newY));
    }
    return Polygon2D(points, color, isInner);
}

void Polygon2D::draw(Renderer2D& renderer, float lineWidth) const {
    renderer.drawPolygon(m_points.size(), m_points.data() ,m_color, lineWidth);
}

const std::vector<glm::vec2>& Polygon2D::getPoints() const {
    return m_points;
}

// equation parametrique + equation cartesienne
bool Polygon2D::intersect(const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& A, const glm::vec2& B, glm::vec2* intersection, glm::vec2* normal) const{
    // Initialisation
    glm::vec2 AB = B - A;
    glm::vec2 normalAB = glm::vec2(AB.y, -AB.x);
    glm::vec2 Ap1 = p1 - A;
    glm::vec2 p1p2 = p2 - p1;

    // Calcul des dot product
    float nABdotAp1 = glm::dot(normalAB, Ap1);
    float nABdotp1p2 = glm::dot(normalAB, p1p2);

    if(nABdotp1p2 == 0) {
        return false;
    }

    // Calcul de t qui remplit les conditions
    float t = -(nABdotAp1 / nABdotp1p2);

    if(t < 0 || t > 1) {
        return false;
    }

    // Equation parametrique avec t pour trouver un point
    glm::vec2 pt = p1 + t * p1p2;

    // Verification intersection
    glm::vec2 Apt = pt - A;
    if(0 <= glm::dot(Apt, AB) && glm::dot(Apt, AB) <= glm::dot(AB, AB)){
        *intersection = pt;
        *normal = glm::normalize(normalAB);
        return true;
    }
    return false;
}

}
