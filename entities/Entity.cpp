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

    char Entity::getChar() const {
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

    int Entity::getLifetime() const {
        return lifetime;
    }

    int Entity::getX() const {
        return x % Simulation::getNC();
    }

    int Entity::getY() const {
        return y % Simulation::getNL();
    }

    void Entity::kill() {
        if (dead) throw EntityAlreadyDead();
        dead = true;
    }

    bool Entity::isDead() const {
        return dead;
    }

    bool Entity::isFood() const {
        return false;
    }

    bool Entity::isAnimal() const {
        return false;
    }

    bool Entity::isAlimMisterio() const {
        return false;
    }

    bool Entity::isAnimMisterio() const {
        return false;
    }

    bool Entity::isBife() const {
        return false;
    }

    bool Entity::isCanguru() const {
        return false;
    }

    bool Entity::isCenoura() const {
        return false;
    }

    bool Entity::isCoelho() const {
        return false;
    }

    bool Entity::isCorpo() const {
        return false;
    }

    bool Entity::isLobo() const {
        return false;
    }

    bool Entity::isOvelha() const {
        return false;
    }

    bool Entity::isRelva() const {
        return false;
    }

}