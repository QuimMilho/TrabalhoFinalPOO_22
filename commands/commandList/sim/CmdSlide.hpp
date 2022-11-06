#ifndef TRABALHOFINALPOO_22_CMDSLIDE_HPP
#define TRABALHOFINALPOO_22_CMDSLIDE_HPP

#include "../../Command.hpp"

namespace tppoo {

    class CmdSlide : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
