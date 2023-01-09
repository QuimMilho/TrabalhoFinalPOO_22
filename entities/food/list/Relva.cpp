#include "Relva.hpp"
#include "../../../exceptions/VarNotFound.hpp"
#include "../../../handler/Handler.hpp"

namespace tppoo {

    Relva::Relva(int x, int y) : Food('r', x, y, "erva verdura", 3, 0) {
        maxLifetime = 20;
        reproduced = false;
        try {
            maxLifetime = Handler::instance->getSimulation()->getVar("VRelva");
        } catch (VarNotFound& e) {
            e.what();
        }
    }

    Relva::~Relva() = default;

    int Relva::tick() {
        addLifetime();
        if (getLifetime() > maxLifetime) {
            kill();
            return 1;
        }
        if (getLifetime() > maxLifetime * 3 / 4 && !reproduced) {
            if (reproduce(8, 4)) reproduced = true;
        }
        return 0;
    }

    bool Relva::isRelva() const {
        return true;
    }

}