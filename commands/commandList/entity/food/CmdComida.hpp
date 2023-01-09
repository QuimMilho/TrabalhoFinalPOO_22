#ifndef TRABALHOFINALPOO_22_CMDCOMIDA_HPP
#define TRABALHOFINALPOO_22_CMDCOMIDA_HPP

#include "../../../Command.hpp"

namespace tppoo {

    class CmdComida : public Command {
        int execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
