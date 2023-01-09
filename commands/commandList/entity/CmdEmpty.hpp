#ifndef TRABALHOFINALPOO_22_CMDEMPTY_HPP
#define TRABALHOFINALPOO_22_CMDEMPTY_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdEmpty : public Command {
        int execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
