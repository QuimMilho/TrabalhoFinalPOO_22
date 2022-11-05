#ifndef TRABALHOFINALPOO_22_SIMULATION_H
#define TRABALHOFINALPOO_22_SIMULATION_H

namespace tppoo {

    class Simulation {
    private:
        static int nl;
        static int nc;
    public:
        static int getNL();
        static int getNC();
        static void setNL(int nl);
        static void setNC(int nc);
    };

}

#endif
