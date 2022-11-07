#include "Animal.hpp"

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

    bool Animal::isAnimal() {
        return true;
    }

    void Animal::setLife(int n) {
        if (n <= 0) kill();
        else life = n;
    }

    int Animal::getLife() {
        return life;
    }

}