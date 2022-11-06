#ifndef TRABALHOFINALPOO_22_CMDSLIDE_H
#define TRABALHOFINALPOO_22_CMDSLIDE_H

#include "../../Command.h"

namespace tppoo {

    class CmdSlide : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
