#include "AlimMisterio.hpp"

namespace tppoo {

    AlimMisterio::AlimMisterio(int x, int y) : Food('a', x, y, "nada", 10, 10) {}

    AlimMisterio::~AlimMisterio() = default;

    int AlimMisterio::tick() {
        return 0;
    }

    bool AlimMisterio::isAlimMisterio() {
        return true;
    }

}