#ifndef TRABALHOFINALPOO_22_ARGSHANDLER_H
#define TRABALHOFINALPOO_22_ARGSHANDLER_H

namespace tppoo {

    class ArgsHandler {
    private:
        void printInfo();
        void postProcessArgs(int argc, char * argv[]);
    public:
        void processArgs(int argc, char* argv[]);
    };

}

#endif
