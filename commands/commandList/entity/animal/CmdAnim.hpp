#ifndef TRABALHOFINALPOO_22_CMDANIM_HPP
#define TRABALHOFINALPOO_22_CMDANIM_HPP

#include "../../../Command.hpp"

namespace tppoo {

    class CmdAnim : public Command{
    public:
        int execute(std::string cmd, std::string *args, int nargs) override;
    };

}

#endif
