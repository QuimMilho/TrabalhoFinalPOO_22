
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
        while (std::getline(file, line) && exit == 0) {
            i++;
            try {
                exit = Handler::instance->getCommandHandler()->executeCommand(line);
            } catch (CommandNotFound& e) {
                std::cout << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << std::endl;
            } catch (NotANumber& e) {
                std::cout << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << std::endl;
            } catch (InvalidArguments& e) {
                std::cout << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << std::endl;
            } catch (FileNotFound& e) {
                std::cout << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << std::endl;
            } catch (EntityNotFound& e) {
                std::cout << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << std::endl;
            } catch (EntityAlreadyDead& e) {
                std::cout << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << std::endl;
            } catch (OutOfBounds& e) {
                std::cout << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << std::endl;
            } catch (WrongType& e) {
                std::cout << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << std::endl;
            } catch (std::exception& e) {
                std::cout << "Ocorreu um erro ao executares o comando numero " << i << ": " << e.what() << std::endl;
            }
        }
        file.close();
        return exit;
    }

}