#include "Cenoura.hpp"

namespace tppoo {

    Cenoura::Cenoura(int x, int y) : Food('t', x, y, "verdura", 4, 1) {}

    Cenoura::~Cenoura() = default;

    int Cenoura::tick() {
        return 0;
    }

    bool Cenoura::isCenoura() {
        return true;
    }

}