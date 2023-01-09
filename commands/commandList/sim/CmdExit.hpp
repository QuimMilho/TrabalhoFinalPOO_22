#ifndef TRABALHOFINALPOO_22_CMDEXIT_HPP
#define TRABALHOFINALPOO_22_CMDEXIT_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdExit : public Command {
    public:
        int execute(std::string cmd, std::string* args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
