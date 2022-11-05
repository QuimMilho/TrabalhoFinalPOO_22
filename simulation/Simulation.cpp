#include "Simulation.h"

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

}