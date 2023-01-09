#ifndef TRABALHOFINALPOO_22_CMDRESTORE_HPP
#define TRABALHOFINALPOO_22_CMDRESTORE_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdRestore : public Command {
        int execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
