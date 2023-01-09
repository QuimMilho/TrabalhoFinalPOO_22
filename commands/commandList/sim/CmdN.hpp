#ifndef TRABALHOFINALPOO_22_CMDN_HPP
#define TRABALHOFINALPOO_22_CMDN_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdN : public Command {
        int execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
