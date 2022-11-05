#include "Animal.h"

namespace tppoo {

    Animal::Animal(char c, int x, int y, int weight, int hunger, int perception) : Entity(c, x, y),
            weight(weight), hunger(hunger), perception(perception) {

    }

}