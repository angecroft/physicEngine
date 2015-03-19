#include <iostream>
#include <cstdlib>

#include <PartyKel/glm.hpp>
#include <PartyKel/WindowManager.hpp>
#include <PartyKel/ParticleManager2D.hpp>
#include <PartyKel/ConstantForce2D.h>
#include <PartyKel/LeapfrogSolver2D.h>
#include <PartyKel/Polygon2D.h>
#include <PartyKel/PolygonForce2D.h>
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

    Polygon2D square = square.buildBox(glm::vec3(1,0.2,0), glm::vec2(-0.9f, -0.9f), 1.8f, 1.8f, true);
    Polygon2D circle = circle.buildCircle(glm::vec3(1,1,1), glm::vec2(0, 0.2f), 0.2f, 32);

    // Creation du Leapfrog solver
    LeapfrogSolver2D leapfrogSolver;
    // Creation des forces des polygones
    float elasticity = 2.f;
    PolygonForce2D polyForceSquare(&square, elasticity, &leapfrogSolver);
    PolygonForce2D polyForceCircle(&circle, elasticity, &leapfrogSolver);

    uint32_t particleCount = 100;

    // Création des particules
    ParticleManager2D particleManager;
    particleManager.addParticle(glm::vec2(0,0), glm::vec2(0,0), 0.2f, glm::vec2(0,0), glm::vec3(1,1,1));
    particleManager.addRandomParticles(particleCount);

//    // Création de la force constante
//    ConstantForce2D constantForce(glm::vec2(0.0001f, 0));


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

        polyForceSquare.setDt(dt);
        polyForceCircle.setDt(dt);

        // Rendu
        renderer.clear();
        square.draw(renderer);
        circle.draw(renderer);
        particleManager.drawParticles(renderer);

        // Simulation
//        constantForce.apply(particleManager);
        leapfrogSolver.solve(particleManager, dt);

        polyForceSquare.apply(particleManager);
        polyForceCircle.apply(particleManager);

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




