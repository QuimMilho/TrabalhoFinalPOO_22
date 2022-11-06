#ifndef TRABALHOFINALPOO_22_CMDKILL_HPP
#define TRABALHOFINALPOO_22_CMDKILL_HPP

#include "../../../Command.hpp"

namespace tppoo {

    class CmdKill : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
