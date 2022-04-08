#ifndef PUSHDOWN
#define PUSHDOWN

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "../utils/vector_utils.h"
#include "./finite_state.h"

namespace machines {
    class Pushdown : private FiniteState {
    private:
        std::vector<char> s; // stack accepted symbols
        std::vector<char> stack; // the actual stack
        char stack_top; // the top of the stack

    public:
        Pushdown();
        Pushdown(
            std::vector<int> states,
            std::vector<char> symbols,
            int initial_state,
            std::vector<int> final_state,
            matrix<int> relation, // this is a 3 dimensional matrix
            std::vector<char> stack_symbols,
            std::vector<char> stack_initial
        );


    };
}

#endif