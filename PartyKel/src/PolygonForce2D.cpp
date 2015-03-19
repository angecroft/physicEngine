#include "PartyKel/PolygonForce2D.h"
#include "PartyKel/ParticleState2D.h"
#include <vector>
#include <iostream>


namespace PartyKel {

PolygonForce2D::PolygonForce2D(const Polygon2D* polygon, float elasticity, const LeapfrogSolver2D* solver) :
    m_Polygon(polygon), m_fElasticity(elasticity), m_Solver(solver), m_fDt(0)
{
}

void PolygonForce2D::setDt(float dt)
{
    m_fDt = dt;
}

void PolygonForce2D::apply(ParticleManager2D& pm)
{
    const std::vector<glm::vec2>& pointPolygon = m_Polygon->getPoints();
    bool isIntersection = false;
    glm::vec2 intersection, normal;

    for(auto it = 0; it < pointPolygon.size(); ++it)
    {
        for(auto itPM = 0; itPM < pm.getPosition().size(); ++itPM)
        {
            ParticleState2D stateParticle = m_Solver->getNextState(itPM, pm, m_fDt);

            auto A = pointPolygon[it];
            auto B = pointPolygon[(it+1)%pointPolygon.size()];

            if(!m_Polygon->m_bIsInner)
            {
                std::swap(A, B);
            }

            isIntersection = m_Polygon->intersect(pm.getPosition()[itPM], stateParticle.position, A, B, &intersection, &normal);
            if(isIntersection)
            {
                glm::vec2 force = m_fElasticity * glm::dot(-normal, stateParticle.velocity) * (pm.getMass()[itPM] / m_fDt) * normal;
                pm.getForces()[itPM] = pm.getForces()[itPM] + force;
            }
        }
    }
}

}
