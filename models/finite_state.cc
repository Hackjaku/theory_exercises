#include "./finite_state.h"

namespace machines {
    void FiniteState::set_states(std::vector<int> states) {
        this->Q = states;
    }

    void FiniteState::set_accepted_symbols(std::vector<char> symbols) {
        this->I = symbols;
    }

    void FiniteState::set_final_states(std::vector<int> final_states) {
        this->F = final_states;
    }

    void FiniteState::set_initial_state(int initial_state) {
        this->q0 = initial_state;
    }

    void FiniteState::set_matrix_relation(matrix<int> relation) {
        this->delta = relation;
    }

    FiniteState::FiniteState() { }
    
    FiniteState::FiniteState(std::vector<int> states, std::vector<char> symbols, int initial_state, std::vector<int> final_states, matrix<int> relation) {
        this->Q = states;
        this->I = symbols;
        this->q0 = initial_state;
        this->F = final_states;
        this->delta = relation;
    }

    std::vector<char> FiniteState::get_symbols() {
        return this->I;
    }
}