#ifndef TRABALHOFINALPOO_22_CMDANIM_H
#define TRABALHOFINALPOO_22_CMDANIM_H

#include "../../../Command.h"

namespace tppoo {

    class CmdAnim : public Command{
    public:
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
