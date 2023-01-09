#include "Entity.hpp"
#include "../exceptions/EntityAlreadyDead.hpp"
#include "../simulation/Simulation.hpp"
#include "../handler/Handler.hpp"
#include "food/list/Relva.hpp"
#include "animal/list/Coelho.hpp"
#include "animal/list/Ovelha.hpp"
#include "animal/list/Lobo.hpp"
#include "animal/list/Canguru.hpp"
#include "../exceptions/OutOfBounds.hpp"

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

    void Entity::setDead() {
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

    bool Entity::createNew(int newX, int newY) {
        if (isRelva()) {
            try {
                Handler::instance->getSimulation()->summon(new Relva(newX, newY));
            } catch (OutOfBounds &e) {
                e.what();
                return false;
            }
            return true;
        } else if (isCoelho()) {
            int weight = Handler::instance->random(1, 4);
            Handler::instance->getSimulation()->summon(new Coelho(newX, newY, weight));
            return true;
        } else if (isOvelha()) {
            int weight = Handler::instance->random(4, 8);
            Ovelha * o = new Ovelha(newX, newY, weight);
            Animal * a = (Animal *) this;
            o->setLife(a->getLife());
            Handler::instance->getSimulation()->summon(o);
            return true;
        } else if (isLobo()) {
            Handler::instance->getSimulation()->summon(new Lobo(newX, newY));
            return true;
        } else if (isCanguru()) {
            Handler::instance->getSimulation()->summon(new Canguru(newX, newY, (Canguru *) this));
            return true;
        }
        return false;
    }

    bool Entity::reproduce(int radius) {
        int relX = Handler::instance->random(radius), newX;
        int relY = Handler::instance->random(radius - relX), newY;
        if (Handler::instance->random(2) == 0) {
            newX = x + relX;
        } else {
            newX = x - relX;
        }
        if (Handler::instance->random(2) == 0) {
            newY = y + relY;
        } else {
            newY = y - relY;
        }
        if (isFood()) {
            if (Handler::instance->getSimulation()->alreadyHasFood(newX, newY)) {
                return false;
            }
        }
        return createNew(newX, newY);
    }

    bool Entity::reproduce(int radiusX, int radiusY) {
        int newX = x + Handler::instance->random(radiusX * 2 + 1) - radiusX;
        int newY = y + Handler::instance->random(radiusY * 2 + 1) - radiusY;
        if (isFood()) {
            if (Handler::instance->getSimulation()->alreadyHasFood(newX, newY)) {
                return false;
            }
        }
        return createNew(newX, newY);
    }

}