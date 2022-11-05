
#include <unordered_map>
#include "Command.h"

#ifndef TRABALHOFINALPOO_22_COMMANDHANDLER_H
#define TRABALHOFINALPOO_22_COMMANDHANDLER_H

namespace tppoo {

    class CommandHandler {
    private:
        std::unordered_map<std::string, Command*> *cmds;
        void registerCmds();
        void registerCmd(std::string name, Command* cmd);
        void unRegisterCmds();
    public:
        CommandHandler();
        ~CommandHandler();
        int executeCommand(std::string cmd);
    };

}

#endif
