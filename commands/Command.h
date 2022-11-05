#include <string>

#ifndef TRABALHOFINALPOO_22_COMMAND_H
#define TRABALHOFINALPOO_22_COMMAND_H

namespace tppoo {

    class Command {
    public:
        virtual int execute(std::string cmd, std::string* args, int nargs);
    };

}

#endif
