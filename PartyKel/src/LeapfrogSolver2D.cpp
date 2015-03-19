#include "PartyKel/LeapfrogSolver2D.h"
#include <iostream>

namespace PartyKel {

// v(t+dt)=v(t)+dt×F/m
// p(t+dt)=p(t)+dt×v(t+dt)
void LeapfrogSolver2D::solve(ParticleManager2D& pm, float dt) {

    for (int i=0; i<pm.getVelocity().size(); ++i)
    {
        pm.getVelocity()[i] = pm.getVelocity()[i] + dt * pm.getForces().at(i) / pm.getMass().at(i);
        pm.getPosition()[i] = pm.getPosition()[i] + dt * pm.getVelocity()[i];
        pm.getForces()[i] = glm::vec2(0, 0);
    }
}

ParticleState2D LeapfrogSolver2D::getNextState(uint32_t particleIdx, ParticleManager2D& pm, float dt) const{
    glm::vec2 velocity = pm.getVelocity()[particleIdx] + dt * pm.getForces()[particleIdx] / pm.getMass()[particleIdx];
    glm::vec2 position = pm.getPosition().at(particleIdx) + dt * velocity;
    ParticleState2D nextState(position, velocity);
    return nextState;
}

}
