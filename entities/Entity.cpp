#include "Entity.hpp"
#include "../exceptions/EntityAlreadyDead.hpp"

namespace tppoo {

    Entity::Entity(char c, int x, int y) : x(x), y(y), representative(c) {
        lifetime = 0;
        dead = false;
    }

    Entity::~Entity() = default;

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
        if (dead) throw EntityAlreadyDead();
        dead = true;
    }

    bool Entity::isDead() {
        return dead;
    }

    void Entity::setRender(bool render) {
        this->render = render;
    }

    bool Entity::toRender() {
        return render;
    }

    bool Entity::isFood() {
        return false;
    }

    bool Entity::isAnimal() {
        return false;
    }

    bool Entity::isAlimMisterio() {
        return false;
    }

    bool Entity::isAnimMisterio() {
        return false;
    }

    bool Entity::isBife() {
        return false;
    }

    bool Entity::isCanguru() {
        return false;
    }

    bool Entity::isCenoura() {
        return false;
    }

    bool Entity::isCoelho() {
        return false;
    }

    bool Entity::isCorpo() {
        return false;
    }

    bool Entity::isLobo() {
        return false;
    }

    bool Entity::isOvelha() {
        return false;
    }

    bool Entity::isRelva() {
        return false;
    }

}