#include <string>

#ifndef TRABALHOFINALPOO_22_ARGSHANDLER_H
#define TRABALHOFINALPOO_22_ARGSHANDLER_H

namespace tppoo {

    int preProcessArgs(int argc, char* argv[]);
    int* processArgs(int argc, std::string* strs);

    void printOptions();

}

#endif
