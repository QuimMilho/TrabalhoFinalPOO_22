#include "Cenoura.hpp"

namespace tppoo {

    Cenoura::Cenoura(int x, int y) : Food('t', x, y, "verdura", 4, 1) {}

    Cenoura::~Cenoura() = default;

    int Cenoura::tick() {
        addLifetime();
        if (getLifetime() % 10 == 0 && getTox() < 3) {
            setTox(getTox() + 1);
        }
        return 0;
    }

    bool Cenoura::isCenoura() const {
        return true;
    }

}