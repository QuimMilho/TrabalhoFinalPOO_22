#include <iostream>
#include "exceptions/InvalidArguments.h"
#include "arguments/ArgsHandler.h"
#include "exceptions/NotANumber.h"
#include "exceptions/OutOfBounds.h"
#include "commands/CommandHandler.h"
#include "exceptions/CommandNotFound.h"
#include "utils/utils.h"

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
    cout << tppoo::getCurrentTime() << endl;
    tppoo::delay(10000);
    cout << tppoo::getCurrentTime() << endl;
    return 0;
}
