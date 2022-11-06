#include "Lobo.hpp"

namespace tppoo {

    Lobo::Lobo(int x, int y) : Animal('L', x, y, 15, 0, 5, 25) {}

    Lobo::~Lobo() = default;

    int Lobo::tick() {
        return 0;
    }

    bool Lobo::isLobo() {
        return true;
    }

}