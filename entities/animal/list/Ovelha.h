#ifndef TRABALHOFINALPOO_22_OVELHA_H
#define TRABALHOFINALPOO_22_OVELHA_H

#include "../Animal.h"

namespace tppoo {

    class Ovelha : public Animal {
    public:
        Ovelha(int x, int y, int weight);
        ~Ovelha() override;
        int tick() override;
        bool isOvelha() override;
    };

}

#endif
