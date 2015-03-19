#pragma once

#include "PartyKel/Force2D.h"

namespace PartyKel {

class GraphBrakeForce2D : public Force2D
{
public:
    GraphBrakeForce2D(float v);
    void setDt(float dt);
    void setGraph(const ParticleGraph* pGraph);
    virtual void apply(ParticleManager2D& pm);

private:
    float m_fV;                         /** Constante associée au frein */
    float m_fDt;                        /** Pas de temps */
    const ParticleGraph* m_pGraph;      /** Particle graph */
};
}
