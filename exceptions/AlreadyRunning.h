#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_ALREADYRUNNING_H
#define TRABALHOFINALPOO_22_ALREADYRUNNING_H

namespace tppoo {

    class AlreadyRunning : std::exception {
    public:
        std::string what() {
            return "A simulação já está a correr!";
        }
    };

}

#endif
