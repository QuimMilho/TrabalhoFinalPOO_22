#ifndef TRABALHOFINALPOO_22_RELVA_HPP
#define TRABALHOFINALPOO_22_RELVA_HPP

#include "../Food.hpp"

namespace tppoo {

    class Relva : public Food {
        int maxLifetime;
        bool reproduced;
    public:
        Relva(int x, int y);
        ~Relva();
        int tick() override;
        bool isRelva() override;
    };

}

#endif
