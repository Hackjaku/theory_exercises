#include "./finite_state_utils.h"

// this function read the standard input to retrieve the number of symbols and puts them into the class vector
int utils::finite_state::input_symbols(machines::FiniteState& fsm) {
    std::cout << "Number of symbols: ";
    int size;
    std::cin >> size;

    std::vector<char> I;
    std::cout << "Insert symbols\n";
    for(unsigned i = 0; i < size; ++i) {
        std::cout << i << ": ";
        char c;
        std::cin >> c;
        I.push_back(c);
    }
    fsm.set_accepted_symbols(I); // the class is passed by reference, so I can update it from there
    return size; // it returns the number of symbols
}

// same as before, but it deals with states
int utils::finite_state::input_states(machines::FiniteState& fsm) {
    std::cout << "Number of states: ";
    int Q_size;
    std::cin >> Q_size;
    std::cout << "Set initial state id: ";
    int q0;
    std::cin >> q0;
    fsm.set_initial_state(q0);
    std::cout << "Number of final states: ";
    int F_size;
    std::cin >> F_size;

    if (Q_size < F_size) {
        return -1; // error
    }

    std::cout << "Insert final states id\n";
    std::vector<int> F;
    for (unsigned i = 0; i < F_size; ++i) {
        std::cout << "F" << i << ": ";
        int Fi;
        std::cin >> Fi;
        F.push_back(Fi);
        std::cout << std::endl;
    }
    fsm.set_final_states(F); // same as before
    return Q_size;
}

// also an input function, but it sets the relation Q x I -> Q
int utils::finite_state::input_relation(machines::FiniteState& fsm, int Q_size, int I_size) {
    try {
        std::cout << std::endl << "Insert destination state index for each pair (Q x I). Insert -1 if input is not defined for state\n\n";
        boost::numeric::ublas::matrix<int> delta(Q_size, I_size); // generated matrix
        std::vector<char> I = fsm.get_symbols(); // I retrieve the symbols to output them (easier for the user to set the relation)
        for (unsigned i = 0; i < Q_size; ++i) {
            std::cout << "-------- Q: " << i << std::endl; // for each state
            for (unsigned j = 0; j < I_size; ++j) { // I cycle each symbol and ask the user what they wants
                int q;
                std::cout << (char)I.at(j) << ": ";
                std::cin >> q; // this is the output state of delta(i, j), the "destination" state if from state i you follow the j arrow
                // todo there must be a check if the state exists
                delta(i, j) = q;
            }
        }
        fsm.set_matrix_relation(delta); // same as the other two functions
        return 0;
    } catch (...) {
        return -1;
    }
}