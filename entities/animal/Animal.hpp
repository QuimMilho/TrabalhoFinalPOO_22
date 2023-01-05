#ifndef TRABALHOFINALPOO_22_ANIMAL_HPP
#define TRABALHOFINALPOO_22_ANIMAL_HPP

#include <string>
#include "../Entity.hpp"

namespace tppoo {

    class Animal : public Entity {
    private:
        int weight, hunger, perception, life;
        std::string smells;
    protected:
        Animal(char c, int x, int y, int weight, int hunger, int perception, int life);
        int getPerc();
    public:
        int getWeight();
        void setLife(int n);
        int getHunger();
        int getLife();
        void setHunger(int n);
        bool isAnimal() const override;
        void setWeight(int n);
    };

}

#endif
