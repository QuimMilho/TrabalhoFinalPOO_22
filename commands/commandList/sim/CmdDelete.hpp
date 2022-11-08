
#ifndef TRABALHOFINALPOO_22_CMDDELETE_HPP
#define TRABALHOFINALPOO_22_CMDDELETE_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdDelete : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
