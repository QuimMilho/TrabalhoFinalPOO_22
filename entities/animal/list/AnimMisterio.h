#ifndef TRABALHOFINALPOO_22_ANIMMISTERIO_H
#define TRABALHOFINALPOO_22_ANIMMISTERIO_H

#include "../Animal.h"

namespace tppoo {

    class AnimMisterio : public Animal{
    public:
        AnimMisterio(int x, int y);
        ~AnimMisterio() override;
        int tick() override;
        bool isAnimMisterio() override;
    };

}

#endif
