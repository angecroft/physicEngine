#pragma once

#include <vector>
#include <PartyKel/renderer/Renderer2D.hpp>
#include <PartyKel/ParticleGraph.h>
#include <PartyKel/glm.hpp>

namespace PartyKel {

class ParticleManager2D {
public:
    ParticleManager2D();
    ParticleManager2D(glm::vec3 color);
    ~ParticleManager2D();

    int addParticle (glm::vec2 const position,
                     glm::vec2 const velocity,
                     float const mass,
                     glm::vec2 const force,
                     glm::vec3 const color);

    void addRandomParticles(unsigned int count);
    void drawParticles(Renderer2D& renderer);
    void drawParticleGraph(ParticleGraph& graph, Renderer2D& renderer);

    std::vector<glm::vec2>& getForces();
    std::vector<glm::vec2>& getPosition();
    std::vector<glm::vec2>& getVelocity();
    std::vector<float>& getMass();
    std::vector<glm::vec3>& getColors();
    glm::vec3 getColor();

    void setColor(glm::vec3 color);

private:
    std::vector<glm::vec2> m_position;
    std::vector<glm::vec2> m_velocity;
    std::vector<float> m_mass;
    std::vector<glm::vec2> m_force;
    std::vector<glm::vec3> m_color;

    glm::vec3 m_colorPM;
};

ParticleGraph createString(glm::vec2 A, glm::vec2 B, glm::vec3 color, uint32_t discFactor, ParticleManager2D& particleManager);

}

