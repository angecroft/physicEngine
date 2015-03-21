#include <iostream>
#include <cstdlib>

#include <PartyKel/glm.hpp>
#include <PartyKel/WindowManager.hpp>
#include <PartyKel/ParticleManager2D.hpp>
#include <PartyKel/LeapfrogSolver2D.h>
#include <PartyKel/Polygon2D.h>
#include <PartyKel/ConstantForce2D.h>
#include <PartyKel/PolygonForce2D.h>
#include <PartyKel/HookForce2D.h>
#include <PartyKel/BrakeForce2D.h>
#include <PartyKel/ParticleState2D.h>
#include <PartyKel/renderer/Renderer2D.hpp>
#include <PartyKel/atb.hpp>

#include <vector>

static const Uint32 WINDOW_WIDTH = 1024;
static const Uint32 WINDOW_HEIGHT = 1024;

using namespace PartyKel;

int main() {
    WindowManager wm(WINDOW_WIDTH, WINDOW_HEIGHT, "Welcome to Hogwarts");
    wm.setFramerate(30);

    SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);

    Renderer2D renderer;

    float elasticity = 2.f;
    LeapfrogSolver2D leapfrogSolver;
    Polygon2D square = square.buildBox(glm::vec3(0.2,0.2,0.2), glm::vec2(-0.9f, -0.9f), 1.8f, 1.8f, true);
    PolygonForce2D polyForceSquare(&square, elasticity, &leapfrogSolver);

    // Hook Force
    HookForce2D hookForce(0.3, 0.2);
    // Brake Force
    BrakeForce2D brakeForce(0.0005);

    uint32_t particleCount = 6;

    // Création des particules
    std::vector<ParticleManager2D> particleManagers;
    particleManagers.push_back(ParticleManager2D (glm::vec3(1,0,.2)));              // Gryffindor
    particleManagers.push_back(ParticleManager2D (glm::vec3(0.2,0,1)));             // Ravenclaw
    particleManagers.push_back(ParticleManager2D (glm::vec3(1,0.8,0)));             // Hufflepuff
    particleManagers.push_back(ParticleManager2D (glm::vec3(0.19,0.6,0.15)));       // Slytherin

    for(int i=0; i<particleManagers.size(); ++i)
        particleManagers[i].addRandomParticles(particleCount);

    // Temps s'écoulant entre chaque frame
    float dt = 0.f;

    bool done = false;
    while(!done) {
        wm.startMainLoop();

        // Rendu
        renderer.clear();
        square.draw(renderer);
        for(int i=0; i<particleManagers.size(); ++i)
            particleManagers[i].drawParticles(renderer);

        // Simulation
        polyForceSquare.apply(particleManagers);
        hookForce.apply(particleManagers);
        brakeForce.apply(particleManagers);
        leapfrogSolver.solve(particleManagers, dt);

        // Gestion des evenements
        SDL_Event e;
        while(wm.pollEvent(e)) {
            if (e.type == SDL_KEYDOWN)
            {
                SDLKey keyPressed = e.key.keysym.sym;

                switch (keyPressed)
                {
                   // Gryffindor
                   case SDLK_z:
                       (particleManagers[0].getVelocity()[0].y > 0.3f) ? particleManagers[0].getVelocity()[0].y = 0.3f : particleManagers[0].getVelocity()[0].y += 0.01f;
                       break;
                   case SDLK_q:
                        (particleManagers[0].getVelocity()[0].x < -0.3f) ? particleManagers[0].getVelocity()[0].x = -0.3f : particleManagers[0].getVelocity()[0].x -= 0.01f;
                        break;
                   case SDLK_d:
                        (particleManagers[0].getVelocity()[0].x > 0.3f) ? particleManagers[0].getVelocity()[0].x = 0.3f : particleManagers[0].getVelocity()[0].x += 0.01f;
                        break;
                   case SDLK_s:
                        (particleManagers[0].getVelocity()[0].y < -0.3f) ? particleManagers[0].getVelocity()[0].y = -0.3f : particleManagers[0].getVelocity()[0].y -= 0.01f;
                        break;
                    // Ravenclaw
                   case SDLK_t:
                        (particleManagers[1].getVelocity()[0].y > 0.3f) ? particleManagers[1].getVelocity()[0].y = 0.3f : particleManagers[1].getVelocity()[0].y += 0.01f;
                        break;
                   case SDLK_f:
                        (particleManagers[1].getVelocity()[0].x < -0.3f) ? particleManagers[1].getVelocity()[0].x = -0.3f : particleManagers[1].getVelocity()[0].x -= 0.01f;
                        break;
                   case SDLK_h:
                        (particleManagers[1].getVelocity()[0].x > 0.3f) ? particleManagers[1].getVelocity()[0].x = 0.3f : particleManagers[1].getVelocity()[0].x += 0.01f;
                        break;
                   case SDLK_g:
                        (particleManagers[1].getVelocity()[0].y < -0.3f) ? particleManagers[1].getVelocity()[0].y = -0.3f : particleManagers[1].getVelocity()[0].y -= 0.01f;
                        break;
                    // Hufflepuff
                   case SDLK_i:
                        (particleManagers[2].getVelocity()[0].y > 0.3f) ? particleManagers[2].getVelocity()[0].y = 0.3f : particleManagers[2].getVelocity()[0].y += 0.01f;
                        break;
                   case SDLK_j:
                        (particleManagers[2].getVelocity()[0].x < -0.3f) ? particleManagers[2].getVelocity()[0].x = -0.3f : particleManagers[2].getVelocity()[0].x -= 0.01f;
                        break;
                   case SDLK_l:
                        (particleManagers[2].getVelocity()[0].x > 0.3f) ? particleManagers[2].getVelocity()[0].x = 0.3f : particleManagers[2].getVelocity()[0].x += 0.01f;
                        break;
                   case SDLK_k:
                        (particleManagers[2].getVelocity()[0].y < -0.3f) ? particleManagers[2].getVelocity()[0].y = -0.3f : particleManagers[2].getVelocity()[0].y -= 0.01f;
                        break;
                    // Slytherin
                   case SDLK_UP:
                        (particleManagers[3].getVelocity()[0].y > 0.3f) ? particleManagers[3].getVelocity()[0].y = 0.3f : particleManagers[3].getVelocity()[0].y += 0.01f;
                        break;
                   case SDLK_LEFT:
                        (particleManagers[3].getVelocity()[0].x < -0.3f) ? particleManagers[3].getVelocity()[0].x = -0.3f : particleManagers[3].getVelocity()[0].x -= 0.01f;
                        break;
                   case SDLK_RIGHT:
                        (particleManagers[3].getVelocity()[0].x > 0.3f) ? particleManagers[3].getVelocity()[0].x = 0.3f : particleManagers[3].getVelocity()[0].x += 0.01f;
                        break;
                   case SDLK_DOWN:
                        (particleManagers[3].getVelocity()[0].y < -0.3f) ? particleManagers[3].getVelocity()[0].y = -0.3f : particleManagers[3].getVelocity()[0].y -= 0.01f;
                        break;

                    default:
                        break;
                }
            }

            switch(e.type) {
                default:
                    break;
                case SDL_QUIT:
                    done = true;
                    break;    
            }
        }

        // Mise à jour de la fenêtre
        dt = wm.update();

        polyForceSquare.setDt(dt);
        brakeForce.setDt(dt);
    }

    return EXIT_SUCCESS;
}






