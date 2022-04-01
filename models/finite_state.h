#ifndef FINITE_STATE
#define FINITE_STATE

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "../utils/vector_utils.h"

namespace machines {
    using namespace std;
    using namespace boost::numeric::ublas;
    class FiniteState {
    public:
        FiniteState();
        void set_states(std::vector<int>);
        void set_accepted_symbols(std::vector<int>);
        void set_initial_state(int);
        void set_matrix_relation(matrix<int>);
        void set_final_states(std::vector<int>);
    private:
        std::vector<int> Q; // machine states
        std::vector<char> I; // machine accepted symbols
        matrix<int> delta; // machine relation (Q x I -> Q)
        int q0; // initial state
        std::vector<int> F; // final states
    };
}

#endif