#include "Ovelha.hpp"
#include "../../../handler/Handler.hpp"
#include "../../../exceptions/VarNotFound.hpp"

namespace tppoo {

    Ovelha::Ovelha(int x, int y, int weight) : Animal('O', x, y, weight, 0, 3, 30) {
        try {
            int s = Handler::instance->getSimulation()->getVar("SOvelha");
            setLife(s);
        } catch (VarNotFound& e) {
            e.what();
        }
    }

    Ovelha::~Ovelha() = default;

    int Ovelha::tick() {
        return 0;
    }

    bool Ovelha::isOvelha() {
        return true;
    }

}