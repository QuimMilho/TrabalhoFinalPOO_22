#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_OUTOFBOUNDS_H
#define TRABALHOFINALPOO_22_OUTOFBOUNDS_H

namespace tppoo {

    class OutOfBounds : std::exception {
    public:
        std::string what() {
            return "Fora dos limites permitidos!";
        }
    };

}

#endif
