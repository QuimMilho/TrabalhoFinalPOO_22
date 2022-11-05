#include <string>

#ifndef TRABALHOFINALPOO_22_COMMAND_H
#define TRABALHOFINALPOO_22_COMMAND_H

namespace tppoo {

    class Command {
    public:
        virtual void execute(std::string cmd, std::string* args, int nargs);
    };

}

#endif
