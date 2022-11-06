#ifndef TRABALHOFINALPOO_22_FOOD_H
#define TRABALHOFINALPOO_22_FOOD_H

#include <string>
#include "../Entity.h"

namespace tppoo {

    class Food : public Entity {
    private:
        std::string smells;
        int nut, tox;
    protected:
        Food(char c, int x, int y, std::string smells, int nut, int tox);
        void setNut(int n);
        void setTox(int n);
    public:
        int getNut();
        int getTox();
        bool isFood() override;
    };

}

#endif
