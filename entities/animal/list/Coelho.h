#ifndef TRABALHOFINALPOO_22_COELHO_H
#define TRABALHOFINALPOO_22_COELHO_H

#include "../Animal.h"

namespace tppoo {

    class Coelho : public Animal {
    public:
        Coelho(int x, int y, int weight);
        ~Coelho() override;
        int tick() override;
        bool isCoelho() override;
    };

}

#endif
