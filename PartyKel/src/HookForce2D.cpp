#include "PartyKel/HookForce2D.h"
#include <PartyKel/glm.hpp>
#include <iostream>
#include <utility>
#include <algorithm>

namespace PartyKel {

HookForce2D::HookForce2D(float K, float L) :
    m_fK(K), m_fL(L)
{
}

void HookForce2D::apply(std::vector<ParticleManager2D> &managers)
{
    const float e = 0.001;

    for(int fatPM = 0; fatPM < managers.size(); ++fatPM)
    {
        int sizeManagers = managers.size();
        auto fatP1 = managers[fatPM].getPosition()[0];

        if(managers[fatPM].getPosition().size() == 1)
        {
            managers[fatPM].getPosition()[0] = glm::vec2(-0.95 + (0.1 * fatPM), 0.95);
            managers[fatPM].getVelocity()[0] = glm::vec2(0);
            continue;
        }

        for (int pm = 1; pm < managers.size(); ++pm)
        {
            for (int particle = 1; particle < managers[(fatPM + pm) % sizeManagers].getPosition().size(); ++particle)
            {
                auto sizePM = managers[(fatPM + pm) % sizeManagers].getPosition().size();
                auto P2 = managers[(fatPM + pm) % sizeManagers].getPosition()[particle];
                float d = glm::distance(fatP1, P2);

                if(d < 0.4f && d > 0.1f)
                {
                    glm::vec2 force = m_fK * (1 - (m_fL / glm::max(d, e))) * (P2 - fatP1);
                    managers[fatPM].getForces()[0] += force;
                    managers[(fatPM + pm) % sizeManagers].getForces()[particle] -= force;
                }
                else if (d < 0.1f)
                {
                    // swap element courant (p2) ala fin du tableau
                    auto positionP2 = managers[(fatPM + pm) % sizeManagers].getPosition().begin() + particle;
                    auto positionEnd = managers[(fatPM + pm) % sizeManagers].getPosition().end();
                    auto velocityP2 = managers[(fatPM + pm) % sizeManagers].getVelocity().begin() + particle;
                    auto velocityEnd = managers[(fatPM + pm) % sizeManagers].getVelocity().end();
                    auto forceP2 = managers[(fatPM + pm) % sizeManagers].getForces().begin() + particle;
                    auto forceEnd = managers[(fatPM + pm) % sizeManagers].getForces().end();

                    if(particle < (sizePM-1))
                    {
                        std::swap(managers[(fatPM + pm) % sizeManagers].getPosition()[particle],
                                        managers[(fatPM + pm) % sizeManagers].getPosition().back());
                        std::swap(managers[(fatPM + pm) % sizeManagers].getVelocity()[particle],
                                        managers[(fatPM + pm) % sizeManagers].getVelocity().back());
                        std::swap(managers[(fatPM + pm) % sizeManagers].getForces()[particle],
                                        managers[(fatPM + pm) % sizeManagers].getForces().back());
                    }

                    managers[fatPM].addParticle(managers[(fatPM + pm) % sizeManagers].getPosition().back(),
                                            managers[(fatPM + pm) % sizeManagers].getVelocity().back(),
                                            0.5f,
                                            managers[(fatPM + pm) % sizeManagers].getForces().back(),
                                            managers[fatPM].getColor());

                    // pop back
                    managers[(fatPM + pm) % sizeManagers].getPosition().pop_back();
                    managers[(fatPM + pm) % sizeManagers].getVelocity().pop_back();
                    managers[(fatPM + pm) % sizeManagers].getForces().pop_back();
                    managers[(fatPM + pm) % sizeManagers].getMass().pop_back();
                    managers[(fatPM + pm) % sizeManagers].getColors().pop_back();
                }
            }
        }
    }
}

}
