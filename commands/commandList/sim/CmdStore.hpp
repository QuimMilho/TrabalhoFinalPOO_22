#ifndef TRABALHOFINALPOO_22_CMDSTORE_HPP
#define TRABALHOFINALPOO_22_CMDSTORE_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdStore : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
