#include "PartyKel/ConstantForce2D.h"


namespace PartyKel {

ConstantForce2D::ConstantForce2D(glm::vec2 force) : m_Force(force) {

}

void ConstantForce2D::apply(ParticleManager2D& pm) {
    for (auto it = pm.getForces().begin(); it != pm.getForces().end(); ++it)
    {
        *it += m_Force;
    }
}
}
