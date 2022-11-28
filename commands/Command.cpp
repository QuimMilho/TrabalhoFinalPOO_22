#include <iostream>
#include "Command.hpp"
#include "../handler/Handler.hpp"

namespace tppoo {

    int Command::execute(std::string cmdName, std::string *args, int nargs) {
        Handler::instance->commandWindow << "Nome do comando: " << cmdName << "\n";
        for (int i = 0; i < nargs; i++) {
            Handler::instance->commandWindow << args[i] << "\n";
        }
        return 0;
    }

}