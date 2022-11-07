#ifndef TRABALHOFINALPOO_22_CMDLOAD_HPP
#define TRABALHOFINALPOO_22_CMDLOAD_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdLoad : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
