#include <exception>

#ifndef TRABALHOFINALPOO_22_INVALIDARGUMENTS_H
#define TRABALHOFINALPOO_22_INVALIDARGUMENTS_H


namespace tppoo {

    class InvalidArguments : public std::exception {
    public:
        char * what();
    };

}


#endif //TRABALHOFINALPOO_22_INVALIDARGUMENTS_H
