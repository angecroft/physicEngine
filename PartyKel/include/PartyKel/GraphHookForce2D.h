#pragma once

#include "PartyKel/Force2D.h"

namespace PartyKel {

class GraphHookForce2D : public Force2D{
public:
    GraphHookForce2D(float K, float L);
    void setGraph(const ParticleGraph* pGraph);
    virtual void apply(ParticleManager2D& pm);

private:
    float m_fK;                         /** Raideur du ressort */
    float m_fL;                         /** Longueur à vide du ressort */
    const ParticleGraph* m_pGraph;      /** Particle graph */

};

}
