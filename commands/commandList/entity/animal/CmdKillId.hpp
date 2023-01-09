#ifndef TRABALHOFINALPOO_22_CMDKILLID_HPP
#define TRABALHOFINALPOO_22_CMDKILLID_HPP

#include "../../../Command.hpp"

namespace tppoo {

    class CmdKillId : public Command {
        int execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
