#ifndef FSM_UTILS
#define FSM_UTILS

#include "../models/finite_state.h"

/*
Companion class to work easily on the base FiniteState class
I didn't want to extend the base class and deal with hierarchy at the moment
*/
namespace utils::finite_state {
    int input_symbols(machines::FiniteState&);
    int input_states(machines::FiniteState&);
    int input_relation(machines::FiniteState&, int, int);
}

#endif
