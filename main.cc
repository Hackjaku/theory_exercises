#include "models/finite_state.h"

using namespace boost::numeric::ublas;
using namespace std;
using namespace utils::vector;

std::vector<char> input_symbols(int);
matrix<int> input_relation(int, int, std::vector<char>);
int input_initial_state();
std::vector<int> input_final_states(int);

int main(int argc, char* argv[]) {
    machines::FiniteState fsm;
    int Q_size, I_size;
    cout << "Nuber of states: ";
    std::cin >> Q_size; // states count
    cout << "Number of symbols: ";
    std::cin >> I_size; // symbols count
    cout << endl;

    cout << "Final states count: ";
    int F_size;
    cin >> F_size; // final states count
    cout << endl;

    
    std::vector<char> I = input_symbols(I_size);
    fsm.set_accepted_symbols(I);


    matrix<int> delta = input_relation(Q_size, I_size, fsm.get_symbols()); // generated matrix
    fsm.set_matrix_relation(delta);

    int q0 = input_initial_state();
    fsm.set_initial_state(q0);

    std::vector<int> F = input_final_states(F_size);
    fsm.set_final_states(F);

    while(true) {
        input_loop:
        try {
            string s;
            cout << "\nINPUT STRING: ";
            cin >> s;
        bool accepted = fsm.validate_input(s);
        cout << (accepted ? "ACCEPTED" : "REJECTED");
        } catch(...) {
            cout << "ERR\n\n";
        }
    }

    return 0;
}

std::vector<char> input_symbols(int size) {
    std::vector<char> I;
    cout << "Insert symbols\n";
    for(unsigned i = 0; i < size; ++i) {
        cout << i << ": ";
        char c;
        cin >> c;
        I.push_back(c);
    }
    return I;
}

matrix<int> input_relation(int Q_size, int I_size, std::vector<char> I) {
    cout << endl << "Insert destination state index for each pair (Q x I). Insert -1 if input is not defined for state\n\n";
    matrix<int> delta(Q_size, I_size); // generated matrix
    for (unsigned i = 0; i < Q_size; ++i) {
        cout << "-------- Q: " << i << endl;
        for (unsigned j = 0; j < I_size; ++j) {
            int q;
            cout << (char)I.at(j) << ": ";
            cin >> q;
            delta(i, j) = q;
        }
    }
    return delta;
}

int input_initial_state() {
    cout << "Initial state: ";
    int q0;
    cin >> q0; // initial state
    return q0;
}

std::vector<int> input_final_states(int size) {
    cout << "Insert final states id\n";
    std::vector<int> F;
    for (unsigned i = 0; i < size; ++i) {
        cout << "F" << i << ": ";
        int Fi;
        cin >> Fi;
        F.push_back(Fi);
        cout << endl;
    }
    return F;
}