#include "PartyKel/ParticleManager2D.hpp"
#include <utility>

namespace PartyKel {

int ParticleManager2D::addParticle(glm::vec2 const position, glm::vec2 const velocity, float const mass, glm::vec2 const force, glm::vec3 const color) {

    m_position.push_back(position);
    m_velocity.push_back(velocity);
    m_mass.push_back(mass);
    m_force.push_back(force);
    m_color.push_back(color);

    return m_position.size()-1;
}

void ParticleManager2D::addRandomParticles(unsigned int count) {
    for(unsigned int i=0; i<count; ++i){
        glm::vec2 positionRand = glm::linearRand(glm::vec2(-0.9f,-0.9f), glm::vec2(0.9f,0.9f));
        glm::vec3 colorRand = glm::linearRand(glm::vec3(0,0,0), glm::vec3(1,1,1));
        addParticle(positionRand, glm::vec2(0.f, 0.f), 0.5f, glm::vec2(0.f, 0.f), colorRand );
    }
}

void ParticleManager2D::drawParticles(Renderer2D& renderer) {
    renderer.drawParticles(m_position.size(),
                           m_position.data(),
                           m_mass.data(),
                           m_color.data());
}

void ParticleManager2D::drawParticleGraph(ParticleGraph& graph, Renderer2D& renderer)
{
    renderer.drawLines(graph.size(),
                       &graph[0],
                       m_position.size(),
                       m_position.data(),
                       m_color.data());
}

std::vector<glm::vec2>& ParticleManager2D::getForces() {
    return m_force;
}

std::vector<glm::vec2>& ParticleManager2D::getPosition() {
    return m_position;
}

std::vector<glm::vec2>& ParticleManager2D::getVelocity() {
    return m_velocity;
}

std::vector<float>& ParticleManager2D::getMass() {
    return m_mass;
}

ParticleGraph createString(glm::vec2 A, glm::vec2 B, glm::vec3 color, uint32_t discFactor, ParticleManager2D& particleManager)
{
    assert(discFactor != 0 && "discFactor can't be negative");
    glm::vec2 AB = B - A;
    glm::vec2 gap = AB / (float)discFactor;
    ParticleGraph particleGraph;
    for(int i=0; i <= discFactor; ++i)
    {
        glm::vec2 position = A + (gap * (float)i);
        int indexParticle = particleManager.addParticle(position, glm::vec2(0), 0.5, glm::vec2(0), color);
        if(indexParticle != 0)
        {
            particleGraph.push_back(std::make_pair(indexParticle-1, indexParticle));
        }
    }
    return particleGraph;
}

}
