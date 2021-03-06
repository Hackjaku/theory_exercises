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
        FiniteState(
            std::vector<int> states,
            std::vector<char> symbols,
            int initial_state,
            std::vector<int> final_state,
            matrix<int> relation
        );
        void set_states(std::vector<int>);
        void set_accepted_symbols(std::vector<char>);
        void set_initial_state(int);
        void set_final_states(std::vector<int>);
        void set_matrix_relation(matrix<int>);

        std::vector<char> get_symbols();
        bool validate_input(std::string);

        FiniteState minimize();
    private:
        std::vector<int> Q; // machine states
        std::vector<char> I; // machine accepted symbols
        matrix<int> delta; // machine relation (Q x I -> Q)
        int q0; // initial state
        std::vector<int> F; // final states

        std::vector<int> reachable_states(); // a new set of reachable states
        void nondistinguishable_states(); // a new set of reachable states
        int transition_function(int, char);
    };
};

#endif