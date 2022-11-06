#include "Ovelha.hpp"

namespace tppoo {

    Ovelha::Ovelha(int x, int y, int weight) : Animal('O', x, y, weight, 0, 3, 30) {}

    Ovelha::~Ovelha() = default;

    int Ovelha::tick() {
        return 0;
    }

    bool Ovelha::isOvelha() {
        return true;
    }

}