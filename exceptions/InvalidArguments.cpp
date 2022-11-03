#include "InvalidArguments.h"

namespace tppoo {

    char *InvalidArguments::what() {
        return (char *) "Invalid Number of Arguments!";
    }

}
