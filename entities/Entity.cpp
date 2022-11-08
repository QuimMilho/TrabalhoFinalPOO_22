#include "Entity.hpp"
#include "../exceptions/EntityAlreadyDead.hpp"
#include "../simulation/Simulation.hpp"

namespace tppoo {

    Entity::Entity(char c, int x, int y) : x(x % Simulation::getNC()), y(y % Simulation::getNL()), representative(c) {
        lifetime = 0;
        dead = false;
        if (x < 0) this->x = Simulation::getNC() - abs(x) % Simulation::getNC();
        if (y < 0) this->y = Simulation::getNL() - abs(y) % Simulation::getNL();
    }

    Entity::~Entity() = default;

    char Entity::getChar() {
        return representative;
    }

    void Entity::addLifetime() {
        lifetime++;
    }

    void Entity::setX(int n) {
        if (n < 0) n = Simulation::getNC() - (abs(n) % Simulation::getNC());
        x = n % Simulation::getNC();
    }

    void Entity::setY(int n) {
        if (n < 0) n = Simulation::getNL() - (abs(n) % Simulation::getNL());
        y = n % Simulation::getNC();
    }

    int Entity::getLifetime() {
        return lifetime;
    }

    int Entity::getX() {
        return x % Simulation::getNC();
    }

    int Entity::getY() {
        return y % Simulation::getNL();
    }

    void Entity::kill() {
        if (dead) throw EntityAlreadyDead();
        dead = true;
    }

    bool Entity::isDead() {
        return dead;
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