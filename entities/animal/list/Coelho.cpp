#include "Coelho.hpp"

namespace tppoo {

    Coelho::Coelho(int x, int y, int weight) : Animal('C', x, y, weight, 0, 4, 20) {}

    Coelho::~Coelho() = default;

    int Coelho::tick() {
        return 0;
    }

    bool Coelho::isCoelho() {
        return true;
    }

}
