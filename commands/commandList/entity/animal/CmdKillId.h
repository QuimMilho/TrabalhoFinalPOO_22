#ifndef TRABALHOFINALPOO_22_CMDKILLID_H
#define TRABALHOFINALPOO_22_CMDKILLID_H

#include "../../../Command.h"

namespace tppoo {

    class CmdKillId : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
