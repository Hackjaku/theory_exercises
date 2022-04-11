#include "./finite_state.h"

using namespace machines;

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

bool FiniteState::validate_input(std::string input) {
    int actual_state = this->q0; // this is the current state of the machine
    for (char in : input) { // for each character (symbol) in the input string
        int index = utils::vector::index_of<char>(in, this->I); // I retrieve the position index of the selected symbol
        if (index == -1) { // if it did not exists
            throw; // TODO define error to be thrown
        } else {
            actual_state = this->delta(actual_state, index); // I check the relation to see where the next state will be
            if (actual_state == -1) { // if the current input is not defined for the current state (IE partial relation and incomplete machine)
                return false; // the machine goes to an implicit sink state, so it will never go to a valid final state
            }
        }
    }
    // now I have completed the input processing phase
    return utils::vector::contains<int>(actual_state, this->F); // I check if the current (last) state is a final one 
}

FiniteState FiniteState::minimize() {
    std::vector<int> reachable_states; // a new set of reachable states
    reachable_states.push_back(this->q0); // I add the initial state to the set of reachable states
    std::vector<int> new_states; // a new set of states
    new_states.push_back(this->q0); // I add the initial state to the set of states

    do {
        std::vector<int> temp; // a temporary set of states
        for (auto q : new_states) { // for each new state
            for (auto c : this->I) { // for each symbol
                temp.push_back(this->transition_function(q, c)); // I add the next state to the temporary set
            }
            new_states = utils::vector::remove_all<int>(temp, reachable_states);
            reachable_states.insert(reachable_states.end(), new_states.begin(), new_states.end());
        }
    } while(new_states.size() > 0);
    return FiniteState(reachable_states, this->I, this->q0, this->F, this->delta);
}

int FiniteState::transition_function(int q, char c) {
    int index = utils::vector::index_of<char>(c, this->I); // the index of the symbol in input
    if (index == -1) { // the symbol is not accepted
        return -1;
    } else {
        return this->delta(q, index); // the destination state (maybe -1)
    }
}
