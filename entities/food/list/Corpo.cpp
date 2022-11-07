
#include "Corpo.hpp"

namespace tppoo {

    Corpo::Corpo(int x, int y, int valorNut) : Food('p', x, y, "carne", valorNut, 0) {}

    Corpo::~Corpo() = default;

    int Corpo::tick() {
        return 0;
    }

    bool Corpo::isCorpo() {
        return true;
    }

}