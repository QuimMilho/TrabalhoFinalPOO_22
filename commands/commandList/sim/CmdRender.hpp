#ifndef TRABALHOFINALPOO_22_CMDRENDER_HPP
#define TRABALHOFINALPOO_22_CMDRENDER_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdRender : public Command {
        int execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
