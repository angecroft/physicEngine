#pragma once

#include <PartyKel/glm.hpp>

namespace PartyKel {

struct ParticleState2D{
    glm::vec2 position;
    glm::vec2 velocity;
    ParticleState2D(glm::vec2 position_, glm::vec2 velocity_){
        position = position_;
        velocity = velocity_;
    }
};

}
