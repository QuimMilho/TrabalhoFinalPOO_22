#include "Food.h"

#include <utility>

namespace tppoo {

    Food::Food(char c, int x, int y, std::string smells, int nut, int tox) : Entity(c, x, y),
            smells(std::move(smells)), nut(nut), tox(tox) {}

    int Food::getNut() {
        return nut;
    }

    int Food::getTox() {
        return tox;
    }

    void Food::setNut(int n) {
        nut = n;
    }

    void Food::setTox(int n) {
        tox = n;
    }

    bool Food::isFood() {
        return true;
    }

}