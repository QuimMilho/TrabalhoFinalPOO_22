#ifndef TRABALHOFINALPOO_22_CORPO_HPP
#define TRABALHOFINALPOO_22_CORPO_HPP

#include "../Food.hpp"

namespace tppoo {

    class Corpo : public Food {
    private:
        int initValorNut, initValorTox;
    public:
        Corpo(int x, int y, int valorNut, int valorTox = 0);
        ~Corpo();
        int tick() override;
        bool isCorpo() override;
        int getInitValorNut() const;
        int getInitValorTox() const;
    };

}

#endif
