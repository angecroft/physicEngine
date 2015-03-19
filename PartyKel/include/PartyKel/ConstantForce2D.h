#pragma once

#include <PartyKel/Force2D.h>
#include <PartyKel/glm.hpp>
#include "PartyKel/ParticleManager2D.hpp"

namespace PartyKel {

class ConstantForce2D : public Force2D {

public:
    ConstantForce2D(glm::vec2 force);
    virtual ~ConstantForce2D() {}
    virtual void apply(ParticleManager2D& pm);

private:
    glm::vec2 m_Force;

};

}
