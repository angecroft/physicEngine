#pragma once

#include "PartyKel/ParticleManager2D.hpp"

namespace PartyKel {

class Force2D {
public:
    virtual ~Force2D() {}
    virtual void apply(ParticleManager2D& pm) = 0;
};

}
