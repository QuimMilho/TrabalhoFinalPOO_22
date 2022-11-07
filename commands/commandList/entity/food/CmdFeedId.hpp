#ifndef TRABALHOFINALPOO_22_CMDFEEDID_HPP
#define TRABALHOFINALPOO_22_CMDFEEDID_HPP

#include "../../../Command.hpp"

namespace tppoo {

    class CmdFeedId : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
