#pragma once

#include "PartyKel/ParticleManager2D.hpp"
#include "PartyKel/ParticleState2D.h"

namespace PartyKel {

class LeapfrogSolver2D{

public:
    void solve(ParticleManager2D& pm, float dt);
    ParticleState2D getNextState(uint32_t particleIdx, ParticleManager2D& pm, float dt) const;
};

}
