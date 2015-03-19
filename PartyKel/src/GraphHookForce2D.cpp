#include "PartyKel/GraphHookForce2D.h"
#include <PartyKel/glm.hpp>
#include <iostream>

namespace PartyKel {

GraphHookForce2D::GraphHookForce2D(float K, float L) : m_fK(K), m_fL(L)
{
    m_pGraph = NULL;
}

void GraphHookForce2D::setGraph(const ParticleGraph* pGraph)
{
    m_pGraph = pGraph;
}

void GraphHookForce2D::apply(ParticleManager2D& pm){
    if(m_pGraph != NULL)
    {
        const float e = 0.001;
        for(auto it_pGraph= m_pGraph->begin(); it_pGraph != m_pGraph->end(); ++it_pGraph)
        {
            unsigned int ind1 = it_pGraph->first;
            unsigned int ind2 = it_pGraph->second;
            auto p1 = pm.getPosition()[ind1];
            auto p2 = pm.getPosition()[ind2];
            float d = glm::distance(p1, p2);
            glm::vec2 force = m_fK * (1 - (m_fL / glm::max(d, e))) * (p2 - p1);
            pm.getForces()[ind1] += force;
            pm.getForces()[ind2] += - force;
        }
    }
}
}

