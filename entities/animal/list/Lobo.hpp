#ifndef TRABALHOFINALPOO_22_LOBO_HPP
#define TRABALHOFINALPOO_22_LOBO_HPP

#include "../Animal.hpp"

namespace tppoo {

    class Lobo : public Animal{
    public:
        Lobo(int x, int y);
        ~Lobo() override;
        int tick() override;
        bool isLobo() const override;
    };

}

#endif
