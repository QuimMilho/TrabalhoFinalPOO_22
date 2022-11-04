#include "args/ArgsHandler.h"
#include "exceptions/InvalidArguments.h"
#include "simulacao/Simulacao.h"
#include "exceptions/NotANumber.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    try {
        tppoo::preProcessArgs(argc, argv);
    } catch (tppoo::InvalidArguments& e) {
        cout << e.what();
        return 1;
    } catch (tppoo::NotANumber& e) {
        cout << e.what();
        return 2;
    }
    return 0;
}
