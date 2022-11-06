#ifndef TRABALHOFINALPOO_22_CMDANIMAL_H
#define TRABALHOFINALPOO_22_CMDANIMAL_H

#include "../../../Command.h"

namespace tppoo {

    class CmdAnimal : public Command {
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
