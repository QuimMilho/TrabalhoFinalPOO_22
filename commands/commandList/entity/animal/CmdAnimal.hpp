#ifndef TRABALHOFINALPOO_22_CMDANIMAL_HPP
#define TRABALHOFINALPOO_22_CMDANIMAL_HPP

#include "../../../Command.hpp"

namespace tppoo {

    class CmdAnimal : public Command {
        int execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) override;
    };

}

#endif
