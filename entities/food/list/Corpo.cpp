
#include "Corpo.hpp"

namespace tppoo {

    Corpo::Corpo(int x, int y, int valorNut, int valorTox) :
            Food('p', x, y, "carne", valorNut, valorTox) {}

    Corpo::~Corpo() = default;

    int Corpo::tick() {
        return 0;
    }

    bool Corpo::isCorpo() {
        return true;
    }

}