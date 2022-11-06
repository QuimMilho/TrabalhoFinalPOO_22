#ifndef TRABALHOFINALPOO_22_LOBO_H
#define TRABALHOFINALPOO_22_LOBO_H

#include "../Animal.h"

namespace tppoo {

    class Lobo : public Animal{
    public:
        Lobo(int x, int y);
        ~Lobo() override;
        int tick() override;
        bool isLobo() override;
    };

}

#endif
