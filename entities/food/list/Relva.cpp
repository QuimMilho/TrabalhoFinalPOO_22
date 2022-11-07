#include "Relva.hpp"

namespace tppoo {

    Relva::Relva(int x, int y) : Food('r', x, y, "erva verdura", 3, 0) {}

    Relva::~Relva() = default;

    int Relva::tick() {
        return 0;
    }

    bool Relva::isRelva() {
        return true;
    }

}