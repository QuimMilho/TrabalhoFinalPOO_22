#include <sstream>
#include <iostream>
#include "CommandHandler.h"
#include "../utils/utils.h"
#include "../exceptions/CommandNotFound.h"

namespace tppoo {

    CommandHandler::CommandHandler() {
        registerCmds();
    }

    CommandHandler::~CommandHandler() {
        unRegisterCmds();
        delete cmds;
    }

    void CommandHandler::registerCmd(std::string name, Command * cmd) {
        cmds->insert(std::pair<std::string, Command*>(name, cmd));
    }

    void CommandHandler::registerCmds() {
        cmds = new std::unordered_map<std::string, Command*>;
        registerCmd("teste", new Command());
    }
    void CommandHandler::unRegisterCmds() {
        for (std::pair<std::string, Command *> s : *cmds) {
            delete s.second;
        }
    }

    void CommandHandler::executeCommand(std::string cmdText) {
        std::stringstream ss(cmdText);

        int n = countArgs(cmdText);
        std::string cmdName;
        ss >> cmdName;
        if (cmds->find(cmdName) == cmds->end())
            throw CommandNotFound();
        Command* cmd = cmds->at(cmdName);
        std::string args[n];

        for (int i = 0; i < n; i++) {
            std::string temp;
            ss >> temp;
            args[i].assign(temp);
        }

        cmd->execute(cmdName, args, n);
    }

}