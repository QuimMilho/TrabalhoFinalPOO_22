#ifndef TRABALHOFINALPOO_22_CMDNEW_HPP
#define TRABALHOFINALPOO_22_CMDNEW_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdNew : public Command {
        int execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
