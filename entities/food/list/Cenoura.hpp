#ifndef TRABALHOFINALPOO_22_CENOURA_HPP
#define TRABALHOFINALPOO_22_CENOURA_HPP

#include "../Food.hpp"

namespace tppoo {

    class Cenoura : public Food {
    public:
        Cenoura(int x, int y);
        ~Cenoura() override;
        int tick() override;
        bool isCenoura() override;
    };

}

#endif
