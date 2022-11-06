#include <iostream>
#include "exceptions/InvalidArguments.h"
#include "arguments/ArgsHandler.h"
#include "exceptions/NotANumber.h"
#include "exceptions/OutOfBounds.h"
#include "commands/CommandHandler.h"
#include "exceptions/CommandNotFound.h"
#include "utils/utils.h"
#include "handler/Handler.h"
#include "exceptions/AlreadyRunning.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        tppoo::ArgsHandler argsHandler;
        argsHandler.processArgs(argc, argv);
    } catch(tppoo::InvalidArguments& e) {
        cout << e.what() << endl;
        return 1;
    } catch(tppoo::NotANumber& e) {
        cout << e.what() << endl;
        return 2;
    } catch(tppoo::OutOfBounds& e) {
        cout << e.what() << endl;
        return 3;
    }
    tppoo::Handler::instance = new tppoo::Handler();
    try {
        tppoo::Handler::instance->start();
    } catch(tppoo::AlreadyRunning& e) {
        cout << e.what() << endl;
        return 4;
    }
    delete tppoo::Handler::instance;
    return 0;
}
