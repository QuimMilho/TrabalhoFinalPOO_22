#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_ENTITYNOTFOUND_H
#define TRABALHOFINALPOO_22_ENTITYNOTFOUND_H

namespace tppoo {

    class EntityNotFound: std::exception {
    public:
        std::string what() {
            return "Essa entidade nao existe!";
        }
    };

}

#endif
