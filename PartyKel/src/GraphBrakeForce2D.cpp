#include "PartyKel/GraphBrakeForce2D.h"
#include <iostream>

namespace PartyKel {

GraphBrakeForce2D::GraphBrakeForce2D(float v) : m_fV(v)
{
    m_fDt = 0.033;
    m_pGraph = NULL;
}

void GraphBrakeForce2D::setDt(float dt)
{
    m_fDt = dt;
}

void GraphBrakeForce2D::setGraph(const ParticleGraph* pGraph)
{
    m_pGraph = pGraph;
}

void GraphBrakeForce2D::apply(ParticleManager2D& pm)
{
    if(m_pGraph != NULL)
    {
        for(auto it_pGraph= m_pGraph->begin(); it_pGraph != m_pGraph->end(); ++it_pGraph)
        {
            unsigned int ind1 = it_pGraph->first;
            unsigned int ind2 = it_pGraph->second;
            auto v1 = pm.getVelocity()[ind1];
            auto v2 = pm.getVelocity()[ind2];
            float force = m_fV / m_fDt;
            pm.getForces()[ind1] += force * (v2 - v1);
            pm.getForces()[ind2] += force * (v1 - v2);
        }
    }
}

}

