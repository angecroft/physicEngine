#pragma once

#include <PartyKel/Force2D.h>
#include <PartyKel/Polygon2D.h>
#include <PartyKel/glm.hpp>
#include <vector>
#include <PartyKel/LeapfrogSolver2D.h>
#include <PartyKel/ParticleState2D.h>

namespace PartyKel {

class PolygonForce2D : public Force2D
{
public:
    PolygonForce2D(const Polygon2D* polygon, float elasticity, const LeapfrogSolver2D* solver);
    void setDt(float dt);
    virtual void apply(std::vector<ParticleManager2D> &managers);

private:
    const Polygon2D* m_Polygon;         /** polygone repoussant les particules */
    float m_fElasticity;                /** a quel point rebondissent les particules sur les polygones */
    const LeapfrogSolver2D* m_Solver;   /** pour obtenir l'etat suivant d'une particule */
    float m_fDt;                        /** a passer a getNextState() */
};

}
