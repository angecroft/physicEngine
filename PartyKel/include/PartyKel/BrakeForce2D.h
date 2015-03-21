#pragma once

#include "PartyKel/Force2D.h"

namespace PartyKel {

class BrakeForce2D : public Force2D
{
public:
    BrakeForce2D(float v);
    void setDt(float dt);
    virtual void apply(std::vector<ParticleManager2D> &managers);

private:
    float m_fV;     /** Constante associée au frein */
    float m_fDt;    /** Pas de temps */
};
}
