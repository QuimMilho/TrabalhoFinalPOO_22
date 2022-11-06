#include <iostream>
#include "exceptions/InvalidArguments.hpp"
#include "arguments/ArgsHandler.hpp"
#include "exceptions/NotANumber.hpp"
#include "exceptions/OutOfBounds.hpp"
#include "commands/CommandHandler.hpp"
#include "exceptions/CommandNotFound.hpp"
#include "utils/utils.hpp"
#include "handler/Handler.hpp"
#include "exceptions/AlreadyRunning.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        tppoo::ArgsHandler argsHandler;
        int exit = argsHandler.processArgs(argc, argv);
        if (exit) return 0;
    } catch(tppoo::InvalidArguments& e) {
        cout << e.what() << endl;
        return 1;
    } catch(tppoo::NotANumber& e) {
        cout << e.what() << endl;
        return 2;
    } catch(tppoo::OutOfBounds& e) {
        cout << e.what() << endl;
        return 3;
    } catch(std::exception& e) {
        cout << e.what() << endl;
        return -1;
    }
    try {
        tppoo::Handler::instance = new tppoo::Handler();
        tppoo::Handler::instance->start();
        delete tppoo::Handler::instance;
    } catch(tppoo::AlreadyRunning& e) {
        cout << e.what() << endl;
        delete tppoo::Handler::instance;
        return 4;
    } catch(std::exception& e) {
        cout << e.what() << endl;
        delete tppoo::Handler::instance;
        return -2;
    }
    return 0;
}
