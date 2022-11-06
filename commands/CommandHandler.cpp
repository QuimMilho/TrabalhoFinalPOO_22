#include <sstream>
#include <iostream>
#include "CommandHandler.hpp"
#include "../utils/utils.hpp"
#include "../exceptions/CommandNotFound.hpp"
#include "commandList/sim/CmdExit.hpp"
#include "commandList/sim/CmdN.hpp"
#include "commandList/entity/animal/CmdAnimal.hpp"
#include "commandList/entity/animal/CmdKill.hpp"
#include "commandList/entity/animal/CmdKillId.hpp"
#include "commandList/entity/animal/CmdAnim.hpp"
#include "commandList/sim/CmdSlide.hpp"

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