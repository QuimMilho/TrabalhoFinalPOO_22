#ifndef TRABALHOFINALPOO_22_CMDKILL_H
#define TRABALHOFINALPOO_22_CMDKILL_H

#include "../../../Command.h"

namespace tppoo {

    class CmdKill : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
