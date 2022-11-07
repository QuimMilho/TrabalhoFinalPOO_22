#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_VARNOTFOUND_HPP
#define TRABALHOFINALPOO_22_VARNOTFOUND_HPP

namespace tppoo {

    class VarNotFound : std::exception {
    public:
        std::string what() {
            return "Definicao de constante nao encontrada!";
        }
    };

}

#endif
