
#include "CmdLoad.hpp"
#include "../../../exceptions/InvalidArguments.hpp"
#include "../../../exceptions/FileNotFound.hpp"
#include "../../../handler/Handler.hpp"
#include "../../../exceptions/CommandNotFound.hpp"
#include "../../../exceptions/NotANumber.hpp"
#include "../../../exceptions/EntityNotFound.hpp"
#include "../../../exceptions/EntityAlreadyDead.hpp"
#include "../../../exceptions/WrongType.hpp"
#include "../../../exceptions/OutOfBounds.hpp"
#include "../../../exceptions/SimulationNotFound.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

namespace tppoo {

    int CmdLoad::execute(std::string cmd, std::string *args, int nargs, std::vector<std::string> &v) {
        if (nargs == 0) throw InvalidArguments();
        std::string fileName, line;
        std::stringstream ss(fileName);
        for (int i = 0; i < nargs; i++) {
            if (i == nargs - 1) {
                fileName.append(args[i]);
            } else {
                fileName.append(args[i]);
                fileName.append(" ");
            }
        }
        std::ifstream file(fileName);
        if (file.fail() || file.bad()) throw FileNotFound();
        int exit = 0, i = 0;
        bool render = false;
        while (std::getline(file, line) && exit != 1) {
            i++;
            std::stringstream cmdSS;
            try {
                cmdSS << line;
                v.push_back(cmdSS.str());
                cmdSS.str(std::string());
                exit = Handler::instance->getCommandHandler()->executeCommand(line, v);
            } catch (CommandNotFound& e) {
                cmdSS << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what();
                v.push_back(cmdSS.str());
            } catch (NotANumber& e) {
                cmdSS << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what();
                v.push_back(cmdSS.str());
            } catch (InvalidArguments& e) {
                cmdSS << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what();
                v.push_back(cmdSS.str());
            } catch (FileNotFound& e) {
                cmdSS << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what();
                v.push_back(cmdSS.str());
            } catch (EntityNotFound& e) {
                cmdSS << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what();
                v.push_back(cmdSS.str());
            } catch (EntityAlreadyDead& e) {
                cmdSS << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what();
                v.push_back(cmdSS.str());
            } catch (OutOfBounds& e) {
                cmdSS << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what();
                v.push_back(cmdSS.str());
            } catch (WrongType& e) {
                cmdSS << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what();
                v.push_back(cmdSS.str());
            } catch (SimulationNotFound& e) {
                cmdSS << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what();
                v.push_back(cmdSS.str());
            } catch (std::exception& e) {
                cmdSS << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what();
                v.push_back(cmdSS.str());
            }
            if (exit == 2) render = true;
        }
        file.close();
        if (exit == 1 && render) return 3;
        if (render) return 2;
        return exit;
    }

}