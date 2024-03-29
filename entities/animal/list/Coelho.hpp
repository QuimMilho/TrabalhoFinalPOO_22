#ifndef TRABALHOFINALPOO_22_COELHO_HPP
#define TRABALHOFINALPOO_22_COELHO_HPP

#include "../Animal.hpp"

namespace tppoo {

    class Coelho : public Animal {
    private:
        int maxLifetime;
    public:
        Coelho(int x, int y, int weight);
        ~Coelho() override;
        int tick() override;
        bool isCoelho() const override;
    };

}

#endif
