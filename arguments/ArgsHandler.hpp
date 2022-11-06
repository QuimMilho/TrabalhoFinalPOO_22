#ifndef TRABALHOFINALPOO_22_ARGSHANDLER_HPP
#define TRABALHOFINALPOO_22_ARGSHANDLER_HPP

namespace tppoo {

    class ArgsHandler {
    private:
        void printInfo();
        void postProcessArgs(int argc, char * argv[]);
    public:
        int processArgs(int argc, char* argv[]);
    };

}

#endif
