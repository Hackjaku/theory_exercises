#include "./finite_state.h"

using namespace boost::numeric::ublas;
using namespace std;
using namespace vector_utils;

int main(int argc, char* argv[]) {
    int Q_size, I_size;
    cout << "Nuber of states: ";
    std::cin >> Q_size; // states count
    cout << "Number of symbols: ";
    std::cin >> I_size; // symbols count
    cout << endl;
    matrix<int> delta(Q_size, I_size); // generated matrix
    std::vector<char> I;
    
    cout << "Insert symbols\n";
    for(unsigned i = 0; i < I_size; ++i) {
        cout << i << ": ";
        char c;
        cin >> c;
        I.push_back(c);
    }
    cout << endl << "Insert destination state index for each pair (Q x I). Insert -1 if input is not defined for state\n\n";

    for (unsigned i = 0; i < Q_size; ++i) {
        cout << "-------- Q: " << i << endl;
        for (unsigned j = 0; j < I_size; ++j) {
            int q;
            cout << (char)I.at(j) << ": ";
            cin >> q;
            delta(i, j) = q;
        }
    }

    cout << "Initial state: ";
    int q0;
    cin >> q0; // initial state
    cout << endl << "Final states count: ";
    int F_size;
    cin >> F_size; // final states count
    cout << endl;

    std::vector<int> F;
    for (unsigned i = 0; i < F_size; ++i) {
        cout << "F" << i << ": ";
        int Fi;
        cin >> Fi;
        F.push_back(Fi);
        cout << endl;
    }

    while(true) {
        input_loop:
        try {
            string s;
            cout << "\nINPUT STRING: ";
            cin >> s;

            int actual_state = q0;
            for (char c : s) {
                int index = index_of<char>(c, I);
                if (index == -1) {
                    cout << "BAD_INPUT\n";
                    goto input_loop;
                } else {
                    actual_state = delta(actual_state, index);
                    if (actual_state == -1) {
                        cout << "REJECTED\n";
                        goto input_loop;
                    }
                }
            }

            cout << ((contains<int>(actual_state, F)) ? "ACCEPTED\n" : "REJECTED\n");
        } catch(...) {
            cout << "ERR\n\n";
        }
    }

    return 0;
}

