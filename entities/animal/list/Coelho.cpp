#include "Coelho.hpp"
#include "../../../exceptions/VarNotFound.hpp"
#include "../../../handler/Handler.hpp"

namespace tppoo {

    Coelho::Coelho(int x, int y, int weight) : Animal('C', x, y, weight, 0, 4, 20) {
        try {
            int s = Handler::instance->getSimulation()->getVar("SCoelho");
            setLife(s);
        } catch (VarNotFound& e) {
            e.what();
        }
    }

    Coelho::~Coelho() = default;

    int Coelho::tick() {
        return 0;
    }

    bool Coelho::isCoelho() {
        return true;
    }

}
