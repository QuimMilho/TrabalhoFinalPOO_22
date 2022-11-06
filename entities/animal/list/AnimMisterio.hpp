#ifndef TRABALHOFINALPOO_22_ANIMMISTERIO_HPP
#define TRABALHOFINALPOO_22_ANIMMISTERIO_HPP

#include "../Animal.hpp"

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
