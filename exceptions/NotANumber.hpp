#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_NOTANUMBER_H
#define TRABALHOFINALPOO_22_NOTANUMBER_H

namespace tppoo {

    class NotANumber : std::exception {
    public:
        std::string what() {
            return "Nao e um numero!";
        }
    };

}

#endif
