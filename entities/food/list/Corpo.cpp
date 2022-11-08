
#include "Corpo.hpp"

namespace tppoo {

    Corpo::Corpo(int x, int y, int valorNut, int valorTox) :
            Food('p', x, y, "carne", valorNut, valorTox),
            initValorNut(valorNut), initValorTox(valorTox) {}

    Corpo::~Corpo() = default;

    int Corpo::tick() {
        return 0;
    }

    bool Corpo::isCorpo() {
        return true;
    }

    int Corpo::getInitValorNut() const {
        return initValorNut;
    }

    int Corpo::getInitValorTox() const {
        return initValorTox;
    }

}