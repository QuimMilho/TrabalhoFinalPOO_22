#include <exception>
#include <string>

#ifndef TRABALHOFINALPOO_22_FILENOTFOUND_H
#define TRABALHOFINALPOO_22_FILENOTFOUND_H

namespace tppoo {

    class FileNotFound : std::exception {
    public:
        std::string what() {
            return "Ficheiro nao encontrado!";
        }
    };

}

#endif
