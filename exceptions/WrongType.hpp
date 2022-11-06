#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_WRONGTYPE_H
#define TRABALHOFINALPOO_22_WRONGTYPE_H

namespace tppoo {

    class WrongType : public std::exception{
    public:
        std::string what() {
            return "Essa entidade e do tipo errado!";
        }
    };

}

#endif
