#include "AnimMisterio.hpp"

namespace tppoo {

    AnimMisterio::AnimMisterio(int x, int y) : Animal('M', x, y, 0, 0, 0, 0) {}

    AnimMisterio::~AnimMisterio() = default;

    int AnimMisterio::tick() {
        return 0;
    }

    bool AnimMisterio::isAnimMisterio() {
        return true;
    }

}