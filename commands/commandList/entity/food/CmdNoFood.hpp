#ifndef TRABALHOFINALPOO_22_CMDNOFOOD_HPP
#define TRABALHOFINALPOO_22_CMDNOFOOD_HPP

#include "../../../Command.hpp"

namespace tppoo {

    class CmdNoFood : public Command {
        int execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
