#pragma once

#include <PartyKel/glm.hpp>
#include <PartyKel/renderer/Renderer2D.hpp>
#include <vector>

namespace PartyKel {

class Polygon2D{

public:
    Polygon2D buildBox(glm::vec3 color, glm::vec2 position, float width, float height, bool isInner = false);
    Polygon2D buildCircle(glm::vec3 color, glm::vec2 center, float radius, size_t discFactor, bool isInner = false);
    void draw(Renderer2D& renderer, float lineWidth = 1.f) const;
    bool intersect(const glm::vec2& p1, const glm::vec2& p2, const glm::vec2& A, const glm::vec2& B, glm::vec2* intersection, glm::vec2* normal) const;
    const std::vector<glm::vec2>& getPoints() const ;
    bool m_bIsInner;

private:
    glm::vec3 m_color;
    std::vector<glm::vec2> m_points;

    Polygon2D(std::vector<glm::vec2> points, glm::vec3 color, bool bIsInner);

};

}

