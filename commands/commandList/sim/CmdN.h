#ifndef TRABALHOFINALPOO_22_CMDN_H
#define TRABALHOFINALPOO_22_CMDN_H

#include "../../Command.h"

namespace tppoo {

    class CmdN : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
