#pragma once

#include "PartyKel/Force2D.h"

namespace PartyKel {

class HookForce2D : public Force2D{
public:
    HookForce2D(float K, float L);
    virtual void apply(ParticleManager2D& pm);

private:
    float m_fK;     /** Raideur du ressort */
    float m_fL;     /** Longueur à vide du ressort */

};

}
