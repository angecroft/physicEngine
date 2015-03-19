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
    WindowManager wm(WINDOW_WIDTH, WINDOW_HEIGHT, "Newton was a Geek");
    wm.setFramerate(30);

    // Initialisation de AntTweakBar (pour la GUI)
    TwInit(TW_OPENGL_CORE, NULL);
    TwWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

    Renderer2D renderer;

    float elasticity = 2.f;
    LeapfrogSolver2D leapfrogSolver;
    Polygon2D square = square.buildBox(glm::vec3(1,0.2,0), glm::vec2(-0.9f, -0.9f), 1.8f, 1.8f, true);
    PolygonForce2D polyForceSquare(&square, elasticity, &leapfrogSolver);

    // Hook Force
    HookForce2D hookForce(0.05, 0.4);
    // Brake Force
    BrakeForce2D brakeForce(0.0001);

    uint32_t particleCount = 20;

    // Création des particules
    ParticleManager2D particleManager;
    particleManager.addParticle(glm::vec2(-.3,0), glm::vec2(0,0), 0.5f, glm::vec2(0,0), glm::vec3(.5,1,.5));
    particleManager.addParticle(glm::vec2(0.3,0), glm::vec2(0,0), 0.5f, glm::vec2(0,0), glm::vec3(1,0,.5));
    particleManager.addParticle(glm::vec2(0,0.3), glm::vec2(0,0), 0.5f, glm::vec2(0,0), glm::vec3(0,0.5,0.5));
    particleManager.addRandomParticles(particleCount);


    TwBar* gui = TwNewBar("Parametres");
    atb::addVarRW(gui, ATB_VAR(particleCount));
    atb::addButton(gui, "reset", [&]() {
        //particleManager.clear();
        particleManager.addParticle(glm::vec2(0,0), glm::vec2(0,0), 0.2f, glm::vec2(0,0), glm::vec3(1,1,1));
        // particleManager.addRandomParticles(particleCount);
    });

    // Temps s'écoulant entre chaque frame
    float dt = 0.f;

    bool done = false;
    while(!done) {
        wm.startMainLoop();

        // Rendu
        renderer.clear();
        square.draw(renderer);
        particleManager.drawParticles(renderer);

        // Simulation
        polyForceSquare.apply(particleManager);
        hookForce.apply(particleManager);
        brakeForce.apply(particleManager);
        leapfrogSolver.solve(particleManager, dt);

        TwDraw();
        // Gestion des evenements
        SDL_Event e;
        while(wm.pollEvent(e)) {
            int handled = TwEventSDL(&e, SDL_MAJOR_VERSION, SDL_MINOR_VERSION);

            if(!handled) {
                switch(e.type) {
                    default:
                        break;
                    case SDL_QUIT:
                        done = true;
                        break;
                }
            }
        }

        // Mise à jour de la fenêtre
        dt = wm.update();

        polyForceSquare.setDt(dt);
        brakeForce.setDt(dt);
    }

    return EXIT_SUCCESS;
}






