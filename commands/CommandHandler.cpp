#include <sstream>
#include <iostream>
#include "CommandHandler.h"
#include "../utils/utils.h"
#include "../exceptions/CommandNotFound.h"
#include "commandList/sim/CmdExit.h"
#include "commandList/sim/CmdN.h"
#include "commandList/entity/animal/CmdAnimal.h"
#include "commandList/entity/animal/CmdKill.h"
#include "commandList/entity/animal/CmdKillId.h"
#include "commandList/entity/animal/CmdAnim.h"
#include "commandList/sim/CmdSlide.h"

namespace tppoo {

    CommandHandler::CommandHandler() {
        registerCmds();
    }

    CommandHandler::~CommandHandler() {
        unRegisterCmds();
        delete cmds;
    }

    void CommandHandler::registerCmd(const std::string name, Command * cmd) {
        cmds->insert(std::pair<std::string, Command*>(name, cmd));
    }

    void CommandHandler::registerCmds() {
        cmds = new std::unordered_map<std::string, Command*>;
        registerCmd("teste", new Command());
        registerCmd("exit", new CmdExit);
        registerCmd("n", new CmdN());
        registerCmd("animal", new CmdAnimal());
        registerCmd("kill", new CmdKill());
        registerCmd("killid", new CmdKillId());
        registerCmd("anim", new CmdAnim());
        registerCmd("slide", new CmdSlide());
    }
    void CommandHandler::unRegisterCmds() {
        for (std::pair<std::string, Command *> s : *cmds) {
            delete s.second;
        }
    }

    int CommandHandler::executeCommand(std::string cmdText) {
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

        int exit = cmd->execute(cmdName, args, n);
        return exit;
    }

}