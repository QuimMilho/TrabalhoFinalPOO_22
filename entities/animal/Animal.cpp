#include "Animal.h"

namespace tppoo {

    Animal::Animal(char c, int x, int y, int weight, int hunger, int perception) : Entity(c, x, y),
            weight(weight), hunger(hunger), perception(perception) {

    }

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
        hunger = n;
    }

    void Animal::setWeight(int n) {
        weight = n;
    }

}