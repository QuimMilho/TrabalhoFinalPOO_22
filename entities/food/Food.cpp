#include "Food.hpp"

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
        if (n < 0) n = 0;
        nut = n;
    }

    void Food::setTox(int n) {
        if (n < 0) n = 0;
        tox = n;
    }

    bool Food::isFood() {
        return true;
    }

}