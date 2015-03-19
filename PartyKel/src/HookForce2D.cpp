#include "PartyKel/HookForce2D.h"
#include <PartyKel/glm.hpp>
#include <iostream>

namespace PartyKel {

HookForce2D::HookForce2D(float K, float L) : m_fK(K), m_fL(L)
{
}

void HookForce2D::apply(ParticleManager2D& pm){
    const float e = 0.001;
    for(auto itPM = 0; itPM < pm.getForces().size(); ++itPM)
    {
        auto p1 = pm.getPosition()[itPM];
        auto p2 = pm.getPosition()[(itPM+1)%pm.getPosition().size()];
        float d = glm::distance(p1, p2);
        glm::vec2 force = m_fK * (1 - (m_fL / glm::max(d, e))) * (p2 - p1);
        pm.getForces()[itPM] = pm.getForces()[itPM] + force;
        pm.getForces()[(itPM+1)%pm.getPosition().size()] = pm.getForces()[(itPM+1)%pm.getPosition().size()] - force;
    }
}
}
