#include "Animal.hpp"
#include "../../handler/Handler.hpp"
#include "../food/Food.hpp"

namespace tppoo {

    Animal::Animal(char c, int x, int y, int weight, int hunger, int perception, int life) : Entity(c, x, y),
            weight(weight), hunger(hunger), perception(perception), life(life) {}

    int Animal::getHunger() {
        return hunger;
    }

    int Animal::getWeight() {
        return weight;
    }

    int Animal::getPerc() {
        return perception;
    }

    void Animal::setHunger(int n) {
        if (n < 0) hunger = 0;
        else hunger = n;
    }

    void Animal::setWeight(int n) {
        if (n < 1) weight = 1;
        else weight = n;
    }

    bool Animal::isAnimal() const {
        return true;
    }

    void Animal::setLife(int n) {
        if (n <= 0) kill();
        else life = n;
    }

    int Animal::getLife() {
        return life;
    }

    void Animal::eat() {
        std::vector<Entity *> v = Handler::instance->getSimulation()->getEntitiesInside(getX(),
                                                                                        getY(), getX(), getY());
        for (Entity * e : v) {
            if (e->isFood()) {
                Food * f = (Food *) e;
                if (!contains(f->getSmells(), smells)) {
                    return;
                }
                setLife(getLife() - f->getTox());
                setHunger(getHunger() + f->getNut());
                f->kill();
                return;
            }
        }
    }

    void Animal::move(int toX, int toY, int howMany) {
        if (toX == -1 || toY == -1) {
            int dir = Handler::instance->random(12);
            if (dir % 2 == 0 || dir > 7) {
                int x = Handler::instance->random(howMany - 1);
                int y = howMany - x;
                if (dir == 0 || dir == 8) {
                    setX(getX() + x);
                    setY(getY() + y);
                } else if (dir == 2 || dir == 9) {
                    setX(getX() - x);
                    setY(getY() + y);
                } else if (dir == 4 || dir == 10) {
                    setX(getX() + x);
                    setY(getY() - y);
                } else if (dir == 6 || dir == 11) {
                    setX(getX() - x);
                    setY(getY() - y);
                }
            } else {
                if (dir == 1) {
                    setX(getX() + howMany);
                } else if (dir == 3) {
                    setX(getX() - howMany);
                } else if (dir == 5) {
                    setY(getY() + howMany);
                } else if (dir == 7) {
                    setY(getY() - howMany);
                }
            }
        } else {
            for (int i = 0; i < howMany; i++) {
                if (toX != getX() && toY != getY()) {
                    if (abs(getX() - toX) > abs(getY() - toY)) {
                        setX(getX() + 1);
                    } else {
                        setY(getY() + 1);
                    }
                } else if (toX != getX()) {
                    setX(getX() + 1);
                } else if (toY != getY()) {
                    setY(getY() + 1);
                }
            }
        }
    }

}