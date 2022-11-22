#ifndef TRABALHOFINALPOO_22_OVELHA_HPP
#define TRABALHOFINALPOO_22_OVELHA_HPP

#include "../Animal.hpp"

namespace tppoo {

    class Ovelha : public Animal {
    public:
        Ovelha(int x, int y, int weight);
        ~Ovelha() override;
        int tick() override;
        bool isOvelha() const override;
    };

}

#endif
