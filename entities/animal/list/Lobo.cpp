#include "Lobo.hpp"
#include "../../../handler/Handler.hpp"
#include "../../../exceptions/VarNotFound.hpp"

namespace tppoo {

    Lobo::Lobo(int x, int y) : Animal('L', x, y, 15, 0, 5, 25) {
        try {
            int s = Handler::instance->getSimulation()->getVar("SLobo");
            setLife(s);
        } catch (VarNotFound& e) {
            e.what();
        }
    }

    Lobo::~Lobo() = default;

    int Lobo::tick() {
        return 0;
    }

    bool Lobo::isLobo() {
        return true;
    }

}