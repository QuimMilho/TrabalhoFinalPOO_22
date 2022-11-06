#ifndef TRABALHOFINALPOO_22_CANGURU_H
#define TRABALHOFINALPOO_22_CANGURU_H

#include "../Animal.h"

namespace tppoo {

    class Canguru : public Animal {
    private:
        Canguru * mother;
    public:
        Canguru(int x, int y, Canguru * mother);
        ~Canguru() override;
        int tick() override;
        bool isCanguru() override;
    };

}

#endif
