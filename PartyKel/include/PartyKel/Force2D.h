#pragma once

#include "PartyKel/ParticleManager2D.hpp"

namespace PartyKel {

class Force2D {
public:
    virtual ~Force2D() {}
    virtual void apply(std::vector<ParticleManager2D> &managers) = 0;
};

}
