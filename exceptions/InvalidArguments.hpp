#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_INVALIDARGUMENTS_H
#define TRABALHOFINALPOO_22_INVALIDARGUMENTS_H

namespace tppoo {

    class InvalidArguments : std::exception {
    public:
        std::string what() {
            return "Argumento invalido!";
        }
    };

}

#endif
