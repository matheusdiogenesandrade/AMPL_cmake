#include <iostream>

#include "ampl/ampl.h"

int main(int argc, char **argv) {
  try {
    // Create an AMPL instance
    ampl::AMPL ampl;

    // If the AMPL installation directory is not in the system search path:
//    ampl::Environment env("/home/matheusdiogenesandrade/ampl");
//    ampl::AMPL ampl(env);
    ampl.setOption("solver", "algencan");
    ampl.read("../toyprob.mod");
    ampl.solve();

    return 0;
  } catch (const std::exception &e) {
    std::cout << e.what() << "\n";
    return 1;
  }
}
