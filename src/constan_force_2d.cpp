#include <iostream>
#include <cstdlib>

#include <PartyKel/glm.hpp>
#include <PartyKel/WindowManager.hpp>
#include <PartyKel/ParticleManager2D.hpp>
#include <PartyKel/ConstantForce2D.h>
#include <PartyKel/LeapfrogSolver2D.h>
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

    uint32_t particleCount = 128;

    // Création des particules
    ParticleManager2D particleManager;
    particleManager.addParticle(glm::vec2(0,0), glm::vec2(0,0), 0.2f, glm::vec2(0,0), glm::vec3(1,1,1));
    particleManager.addRandomParticles(particleCount);

    // Création de la force constante
    ConstantForce2D constantForce(glm::vec2(0.01f, 0));

    // Création du Leapfrog solver
    LeapfrogSolver2D leapfrogSolver;

    TwBar* gui = TwNewBar("Parametres");
    float randomMoveScale = 0.05f;

    atb::addVarRW(gui, ATB_VAR(randomMoveScale), " step=0.01 ");
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
        particleManager.drawParticles(renderer);

        // Simulation
        //particleManager.move(dt * randomMoveScale);
        constantForce.apply(particleManager);
        leapfrogSolver.solve(particleManager, dt);
//        std::cout << "force particule 1 : "<< particleManager.getForces()[0] << std::endl;

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
    }

    return EXIT_SUCCESS;
}


