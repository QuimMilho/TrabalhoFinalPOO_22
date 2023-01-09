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
#include "commandList/entity/animal/CmdVisanim.hpp"
#include "commandList/entity/CmdSee.hpp"
#include "commandList/entity/CmdInfo.hpp"
#include "commandList/cmd/CmdLoad.hpp"
#include "commandList/entity/food/CmdFood.hpp"
#include "commandList/entity/CmdEmpty.hpp"
#include "commandList/entity/food/CmdFeed.hpp"
#include "commandList/entity/food/CmdFeedId.hpp"
#include "commandList/entity/food/CmdNoFood.hpp"
#include "commandList/sim/CmdStore.hpp"
#include "commandList/sim/CmdRestore.hpp"
#include "commandList/sim/CmdDelete.hpp"
#include "commandList/sim/CmdNew.hpp"
#include "commandList/sim/CmdRender.hpp"
#include "commandList/entity/food/CmdComida.hpp"
#include "../handler/Handler.hpp"

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
        registerCmd("visanim", new CmdVisanim());
        registerCmd("see", new CmdSee());
        registerCmd("info", new CmdInfo());
        registerCmd("load", new CmdLoad());
        registerCmd("food", new CmdFood());
        registerCmd("empty", new CmdEmpty());
        registerCmd("feed", new CmdFeed());
        registerCmd("feedid", new CmdFeedId());
        registerCmd("nofood", new CmdNoFood());
        registerCmd("store", new CmdStore());
        registerCmd("restore", new CmdRestore());
        registerCmd("delete", new CmdDelete());
        registerCmd("new", new CmdNew());
        registerCmd("render", new CmdRender());
        registerCmd("comida", new CmdComida());
    }
    void CommandHandler::unRegisterCmds() {
        for (std::pair<std::string, Command *> s : *cmds) {
            delete s.second;
        }
    }

    int CommandHandler::executeCommand(std::string cmdText, std::vector<std::string> &v) {
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

        int exit = cmd->execute(cmdName, args, n, v);

        return exit;
    }

    void CommandHandler::show(std::vector<std::string> &v) {
        Handler::instance->commandWindow.clear();
        if (v.size() == 0) return;
        if (v.size() < 6) {
            Handler::instance->commandWindow << "Page 1 of 1" << "\n";
            for (std::string s : v)
                Handler::instance->commandWindow << s << "\n";
        } else {
            int page = 0, maxPage = (((int) v.size()) / 5);
            if (v.size() % 5 != 0) maxPage++;
            std::string input;
            do {
                Handler::instance->commandWindow << "Page " << page + 1 << " of " << maxPage << "\n";
                for (int i = page * 5; i < (page + 1) * 5; i++) {
                    if (i < v.size())
                    Handler::instance->commandWindow << v.at(i) << "\n";
                }
                Handler::instance->commandWindow >> input;
                if (input == "KEY_RIGHT") {
                    if (page < maxPage - 1) page++;
                } else if (input == "KEY_LEFT") {
                    if (page > 0) page--;
                }
                Handler::instance->commandWindow.clear();
            } while (input == "KEY_RIGHT" || input == "KEY_LEFT");
        }
    }


}