#include "Canguru.h"

namespace tppoo {

    Canguru::Canguru(int x, int y, Canguru * mother) : Animal('C', x, y, 10, 0, 7, 20),
            mother(mother) {}

    Canguru::~Canguru() = default;

    int Canguru::tick() {
        return 0;
    }

    bool Canguru::isCanguru() {
        return true;
    }

}