#ifndef TRABALHOFINALPOO_22_CMDINFO_HPP
#define TRABALHOFINALPOO_22_CMDINFO_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdInfo : public Command {
        int execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
