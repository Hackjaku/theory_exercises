#ifndef FSM_UTILS
#define FSM_UTILS

#include "../models/finite_state.h"

namespace utils::finite_state {
    int input_symbols(machines::FiniteState&);
    int input_states(machines::FiniteState&);
    int input_relation(machines::FiniteState&, int, int);
}

#endif
