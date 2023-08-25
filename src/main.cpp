#include <iostream>
#include <string> 

#include <range/v3/all.hpp> // get everything

#include "ampl/ampl.h"

namespace rangesv3 = ::ranges;

using namespace std;
using namespace ampl;

int main(int argc, char **argv) {
    try {
        int n = 10;

        // Create an AMPL instance
        AMPL ampl;

        // sets
        ampl.eval("set N;");
        ampl.eval("param distance {N, N};");
        

        // N
        vector<string> N = rangesv3::views::iota(0, n)
            | rangesv3::views::transform([](const int& i) -> string { return to_string(i); })
            | rangesv3::to<vector<string>>();

        vector<const char *> N_ptr = N 
            | rangesv3::views::transform([](const string& i_str) -> const char * { return i_str.data(); })
            | rangesv3::to<vector<const char *>>();

        DataFrame N_df(1, "N");
        N_df.setColumn("N", N_ptr.data(), n);
        ampl.setData(N_df, "N");

        // distances
        vector<vector<double>> distances_double (n, vector<double>(n));
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) 
                distances_double[i][j] = i * j;


        vector<const double *> distances = distances_double 
             | rangesv3::views::transform([](const vector<double>& distance_line) -> const double * { 
                 return distance_line.data(); 
                 })
             | rangesv3::to<vector<const double *>>();


        DataFrame distance_df = DataFrame(2, StringArgs("N", "N", "distance"));
        distance_df.setMatrix(N_ptr.data(), N_ptr.data(), distances.data());
        ampl.setData(distance_df);

        return 0;
    } catch (const std::exception &e) {
        std::cout << e.what() << "\n";
        return 1;
    }
}
