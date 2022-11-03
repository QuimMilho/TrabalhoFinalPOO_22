#include "args/ArgsHandler.h"
#include "exceptions/InvalidArguments.h"
#include "simulacao/Simulacao.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    try {
        tppoo::preProcessArgs(argc, argv);
    } catch (tppoo::InvalidArguments& e) {
        cout << e.what();
        return 0;
    }
    return 0;
}
