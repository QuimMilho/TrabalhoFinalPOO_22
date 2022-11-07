#ifndef TRABALHOFINALPOO_22_CMDSEE_HPP
#define TRABALHOFINALPOO_22_CMDSEE_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdSee : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
