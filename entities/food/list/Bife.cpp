#include "Bife.hpp"

namespace tppoo {

    Bife::Bife(int x, int y) : Food('b', x, y, "carne ketchup", 10, 2) {}

    Bife::~Bife() = default;

    int Bife::tick() {
        addLifetime();
        if (getLifetime() > 30) {
            kill();
            return 1;
        }
        setNut(getNut() - 1);
        return 0;
    }

    bool Bife::isBife() const {
        return true;
    }

}