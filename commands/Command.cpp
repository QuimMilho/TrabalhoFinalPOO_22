#include <iostream>
#include "Command.h"

namespace tppoo {

    void Command::execute(std::string cmdName, std::string *args, int nargs) {
        std::cout << "Nome do comando: " << cmdName << std::endl;
        for (int i = 0; i < nargs; i++) {
            std::cout << args[i] << std::endl;
        }
    }

}