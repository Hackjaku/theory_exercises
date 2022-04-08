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
    };
}

#endif