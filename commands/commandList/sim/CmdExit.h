#ifndef TRABALHOFINALPOO_22_CMDEXIT_H
#define TRABALHOFINALPOO_22_CMDEXIT_H

#include "../../Command.h"

namespace tppoo {

    class CmdExit : public Command {
    public:
        int execute(std::string cmd, std::string* args, int nargs) override;
    };

}

#endif
