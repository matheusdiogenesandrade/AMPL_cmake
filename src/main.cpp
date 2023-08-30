#include <iostream>
#include <string> 

#include "ampl/ampl.h"

using namespace std;
using namespace ampl;

int main(int argc, char **argv) {
    try {
        /* INPUT */

        // Nodes ids
        size_t n = 10;

        char ** V = (char **) malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            // up to 10 characters of id
            V[i] = (char *) malloc(10 * sizeof(char));
            sprintf(V[i], "%d", i);
        }

        // Arcs
        vector<pair<int, int>> A = {make_pair(1, 0), make_pair(2, 5)};

        /* AMPL process */
        AMPL ampl;

        // Sets
        // Nodes
        ampl.eval("set V;");
        ampl.getSet("V").setValues(V, n);

        // Arcs
        ampl.eval("set A within {V,V};");
        ampl.getSet("A");
        // how to set A???

        // cost
        ampl.eval("param cost{A};");
        ampl.getParameter("cost");
        // how to set populate cost???

        // Closing
        ampl.close();

        // Cleaning
        for (int i = 0; i < n; i++) 
            free(V[i]);
        free(V);

        return 0;
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
        return 1;
    }
}
