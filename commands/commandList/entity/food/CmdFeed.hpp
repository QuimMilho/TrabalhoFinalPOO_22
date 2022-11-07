#ifndef TRABALHOFINALPOO_22_CMDFEED_HPP
#define TRABALHOFINALPOO_22_CMDFEED_HPP

#include "../../../Command.hpp"

namespace tppoo {

    class CmdFeed : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
