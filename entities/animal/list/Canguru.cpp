#include "Canguru.hpp"
#include "../../../handler/Handler.hpp"
#include "../../../exceptions/VarNotFound.hpp"

namespace tppoo {

    Canguru::Canguru(int x, int y, Canguru * mother) : Animal('C', x, y, 10, 0, 7, 20),
            mother(mother) {
        try {
            int s = Handler::instance->getSimulation()->getVar("SCanguru");
            setLife(s);
        } catch (VarNotFound& e) {
            e.what();
        }
    }

    Canguru::~Canguru() = default;

    int Canguru::tick() {
        return 0;
    }

    bool Canguru::isCanguru() const {
        return true;
    }

}