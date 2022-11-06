#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_COMMANDNOTFOUND_H
#define TRABALHOFINALPOO_22_COMMANDNOTFOUND_H

namespace tppoo {

    class CommandNotFound : std::exception {
    public:
        std::string what() {
            return "Comando nao existe!";
        }
    };

}

#endif
