
#include "Corpo.hpp"

namespace tppoo {

    Corpo::Corpo(int x, int y, int valorNut, int valorTox) :
            Food('p', x, y, "carne", valorNut, valorTox),
            initValorNut(valorNut), initValorTox(valorTox) {}

    Corpo::~Corpo() = default;

    int Corpo::tick() {
        addLifetime();
        if (getTox() < 2 * initValorTox) {
            setTox(getTox() + 1);
        }
        setNut(getNut() - 1);
        return 0;
    }

    bool Corpo::isCorpo() const {
        return true;
    }

    int Corpo::getInitValorNut() const {
        return initValorNut;
    }

    int Corpo::getInitValorTox() const {
        return initValorTox;
    }

}