
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

    int CmdLoad::execute(std::string cmd, std::string *args, int nargs) {
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
            try {
                exit = Handler::instance->getCommandHandler()->executeCommand(line);
            } catch (CommandNotFound& e) {
                Handler::instance->commandWindow << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << "\n";
            } catch (NotANumber& e) {
                Handler::instance->commandWindow << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << "\n";
            } catch (InvalidArguments& e) {
                Handler::instance->commandWindow << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << "\n";
            } catch (FileNotFound& e) {
                Handler::instance->commandWindow << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << "\n";
            } catch (EntityNotFound& e) {
                Handler::instance->commandWindow << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << "\n";
            } catch (EntityAlreadyDead& e) {
                Handler::instance->commandWindow << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << "\n";
            } catch (OutOfBounds& e) {
                Handler::instance->commandWindow << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << "\n";
            } catch (WrongType& e) {
                Handler::instance->commandWindow << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << "\n";
            } catch (SimulationNotFound& e) {
                Handler::instance->commandWindow << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << "\n";
            } catch (std::exception& e) {
                Handler::instance->commandWindow << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << "\n";
            }
            if (exit == 2) render = true;
        }
        file.close();
        if (exit == 1 && render) return 3;
        if (render) return 2;
        return exit;
    }

}