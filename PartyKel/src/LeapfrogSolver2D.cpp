#include "PartyKel/LeapfrogSolver2D.h"
#include <iostream>

namespace PartyKel {

// v(t+dt)=v(t)+dt×F/m
// p(t+dt)=p(t)+dt×v(t+dt)
void LeapfrogSolver2D::solve(std::vector<ParticleManager2D> &managers, float dt)
{
    for(int i = 0; i < managers.size(); ++i)
    {
        for (int j=0; j<managers[i].getVelocity().size(); ++j)
        {
            managers[i].getVelocity()[j] = managers[i].getVelocity()[j] + dt * managers[i].getForces()[j] / managers[i].getMass()[j];
            managers[i].getPosition()[j] = managers[i].getPosition()[j] + dt * managers[i].getVelocity()[j];
            managers[i].getForces()[j] = glm::vec2(0, 0);
        }
    }
}

ParticleState2D LeapfrogSolver2D::getNextState(uint32_t particleIdx, ParticleManager2D& pm, float dt) const
{
    glm::vec2 velocity = pm.getVelocity()[particleIdx] + dt * pm.getForces()[particleIdx] / pm.getMass()[particleIdx];
    glm::vec2 position = pm.getPosition().at(particleIdx) + dt * velocity;
    ParticleState2D nextState(position, velocity);
    return nextState;
}

}
