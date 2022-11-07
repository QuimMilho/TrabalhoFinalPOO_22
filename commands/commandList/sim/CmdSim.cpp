#include "CmdExit.hpp"
#include "CmdN.hpp"
#include "../../../handler/Handler.hpp"
#include "../../../exceptions/OutOfBounds.hpp"
#include "../../../exceptions/InvalidArguments.hpp"
#include "CmdSlide.hpp"
#include "../../../exceptions/NotANumber.hpp"

namespace tppoo {

    int CmdExit::execute(std::string cmd, std::string *args, int nargs) {
        return 1;
    }

    int CmdN::execute(std::string cmd, std::string *args, int nargs) {
        int n, p;
        switch (nargs) {
            case 0:
                Handler::instance->getSimulation()->tick();
                Handler::instance->getSimulation()->render();
                break;
            case 1:
                n = toNumber(args[0]);
                if (n <= 0) throw OutOfBounds();
                Handler::instance->getSimulation()->tickMultiple(n);
                break;
            case 2:
                n = toNumber(args[0]);
                p = toNumber(args[1]);
                if (n <= 0 || p <= 0) throw OutOfBounds();
                Handler::instance->getSimulation()->tickMultiple(n, p);
                break;
            default:
                throw InvalidArguments();
        }
        return 0;
    }

    int CmdSlide::execute(std::string cmd, std::string *args, int nargs) {
        if (nargs != 2) {
            throw InvalidArguments();
        }
        int n = toNumber(args[1]);
        if (isNumber(args[0])) {
            Handler::instance->getSimulation()->addOffset(toNumber(args[0]), n);
            return 0;
        }
        if (n <= 0) throw OutOfBounds();
        if (args[0] == "up") {
            Handler::instance->getSimulation()->addYOffset(-n);
        } else if (args[0] == "down") {
            Handler::instance->getSimulation()->addYOffset(n);
        } else if (args[0] == "right") {
            Handler::instance->getSimulation()->addXOffset(n);
        } else if (args[0] == "left") {
            Handler::instance->getSimulation()->addXOffset(-n);
        } else throw InvalidArguments();
        return 2;
    }

}
