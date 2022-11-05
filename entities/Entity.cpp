#include "Entity.h"

namespace tppoo {

    Entity::Entity(char c, int x, int y) : x(x), y(y), representative(c) {
        lifetime = 0;
        dead = false;
    }

    char Entity::getChar() {
        return representative;
    }

    void Entity::addLifetime() {
        lifetime++;
    }

    void Entity::setX(int n) {
        x = n;
    }

    void Entity::setY(int n) {
        y = n;
    }

    int Entity::getLifetime() {
        return lifetime;
    }

    int Entity::getX() {
        return x;
    }

    int Entity::getY() {
        return y;
    }

    void Entity::kill() {
        dead = true;
    }

}