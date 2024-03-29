
#ifndef TRABALHOFINALPOO_22_BIFE_HPP
#define TRABALHOFINALPOO_22_BIFE_HPP

#include "../Food.hpp"

namespace tppoo {

    class Bife : public Food {
    public:
        Bife(int x, int y);
        ~Bife();
        int tick() override;
        bool isBife() const override;
    };

}

#endif
