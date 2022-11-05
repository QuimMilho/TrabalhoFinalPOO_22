#include "Simulation.h"
#include "../utils/utils.h"

namespace tppoo {

    int Simulation::nc = 0;
    int Simulation::nl = 0;

    int Simulation::getNL() {
        return nl;
    }

    int Simulation::getNC() {
        return nc;
    }

    void Simulation::setNL(int value) {
        nl = value;
    }

    void Simulation::setNC(int value) {
        nc = value;
    }

    void Simulation::tick() {

    }

    void Simulation::render() {

    }

    void Simulation::tickMultiple(int n) {
        for (int i = 0; i < n; i++) {
            tick();
        }
        render();
    }

    void Simulation::tickTimed(int n, int t) {
        for (int i = 0; i < n; i++) {
            tick();
            render();
            delay(1000 * t);
        }
    }

    void Simulation::start() {

    }

}