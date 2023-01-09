#include <iostream>
#include <sstream>
#include "Command.hpp"
#include "../handler/Handler.hpp"

namespace tppoo {

    int Command::execute(std::string cmdName, std::string *args, int nargs, std::vector<std::string> &v) {
        std::stringstream ss;
        ss << "Nome do comando: " << cmdName;
        v.push_back(ss.str());
        for (int i = 0; i < nargs; i++) {
            ss.str(std::string());
            ss << args[i] << "\n";
            v.push_back(ss.str());
        }
        return 0;
    }

}