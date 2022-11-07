#include "Bife.hpp"

namespace tppoo {

    Bife::Bife(int x, int y) : Food('b', x, y, "carne ketchup", 10, 2) {}

    Bife::~Bife() = default;

    int Bife::tick() {
        return 0;
    }

    bool Bife::isBife() {
        return true;
    }

}