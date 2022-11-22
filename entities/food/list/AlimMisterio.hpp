#ifndef TRABALHOFINALPOO_22_ALIMMISTERIO_HPP
#define TRABALHOFINALPOO_22_ALIMMISTERIO_HPP

#include "../Food.hpp"

namespace tppoo {

    class AlimMisterio : public Food {
    public:
        AlimMisterio(int x, int y);
        ~AlimMisterio();
        int tick() override;
        bool isAlimMisterio() const override;
    };

}

#endif
