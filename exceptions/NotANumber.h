#include <exception>

#ifndef TRABALHOFINALPOO_22_NOTANUMBER_H
#define TRABALHOFINALPOO_22_NOTANUMBER_H

namespace tppoo {

    class NotANumber : public std::exception {
    public:
        char * what();
    };

}

#endif
