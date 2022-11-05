#ifndef TRABALHOFINALPOO_22_ANIMAL_H
#define TRABALHOFINALPOO_22_ANIMAL_H

#include <string>
#include "../Entity.h"

namespace tppoo {

    class Animal : public Entity{
    private:
        int weight, hunger, perception;
        std::string smells;
    protected:
        Animal(char c, int x, int y, int weight, int hunger, int perception);
        void setWeight(int n);
        void setHunger(int n);
    public:
        int getWeight();
        int getHunger();
        int getPerc();
    };

}

#endif
