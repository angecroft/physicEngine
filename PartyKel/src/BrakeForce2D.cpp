#include "PartyKel/BrakeForce2D.h"
#include <iostream>

namespace PartyKel {

BrakeForce2D::BrakeForce2D(float v) :
    m_fV(v), m_fDt(0.033f)
{
}

void BrakeForce2D::setDt(float dt)
{
    m_fDt = dt;
}

void BrakeForce2D::apply(std::vector<ParticleManager2D> &managers)
{
    for(int itPM = 0; itPM < managers.size(); ++itPM)
    {
        for(int itParticle = 1; itParticle < managers[itPM].getVelocity().size(); ++itParticle)
        {
            auto v1 = managers[itPM].getVelocity()[itParticle];
            auto v2 = managers[itPM].getVelocity()[(itParticle+1) % managers[itPM].getVelocity().size()];
            float force = m_fV / m_fDt;
            managers[itPM].getForces()[itParticle] += (force * (v2 - v1));
            managers[itPM].getForces()[(itParticle+1) % managers[itPM].getVelocity().size()] += (force * (v1 - v2));
        }
    }
//    for(auto itPM = 0; itPM < pm.getVelocity().size(); ++itPM)
//    {
//        auto v1 = pm.getVelocity()[itPM];
//        auto v2 = pm.getVelocity()[(itPM+1)%pm.getVelocity().size()];
//        float force = m_fV / m_fDt;
//        pm.getForces()[itPM] = pm.getForces()[itPM] + (force * (v2 - v1));
//        pm.getForces()[(itPM+1)%pm.getVelocity().size()] = pm.getForces()[(itPM+1)%pm.getVelocity().size()] + (force * (v1 - v2));
//    }
}

}
