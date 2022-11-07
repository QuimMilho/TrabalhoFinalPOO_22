#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_ENTITYALREADYDEAD_H
#define TRABALHOFINALPOO_22_ENTITYALREADYDEAD_H

namespace tppoo {

    class EntityAlreadyDead : std::exception {
    public:
        std::string what() {
            return "Essa entidade ja morreu!";
        }
    };

}

#endif
