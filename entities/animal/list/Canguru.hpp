#ifndef TRABALHOFINALPOO_22_CANGURU_HPP
#define TRABALHOFINALPOO_22_CANGURU_HPP

#include "../Animal.hpp"

namespace tppoo {

    class Canguru : public Animal {
    private:
        Canguru * mother;
        int maxLifetime;
    public:
        Canguru(int x, int y, Canguru * mother);
        ~Canguru() override;
        int tick() override;
        bool isCanguru() const override;
        void kill() override;
    };

}

#endif
