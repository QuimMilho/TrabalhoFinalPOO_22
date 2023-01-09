#ifndef TRABALHOFINALPOO_22_FOOD_HPP
#define TRABALHOFINALPOO_22_FOOD_HPP

#include <string>
#include "../Entity.hpp"

namespace tppoo {

    class Food : public Entity {
    private:
        std::string smells;
        int nut, tox;
    protected:
        Food(char c, int x, int y, std::string smells, int nut, int tox);
    public:
        int getNut();
        int getTox();
        bool isFood() const override;
        void setNut(int n);
        void setTox(int n);

        std::string getSmells() const;
    };

}

#endif
