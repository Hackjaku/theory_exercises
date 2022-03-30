#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <iostream>
#include <vector>
#include <string>

using namespace boost::numeric::ublas;
using namespace std;

int main(int argc, char* argv[]) {
    int Q_size, I_size;
    cout << "Nuber of states: ";
    std::cin >> Q_size; // states count
    cout << "Number of symbols: ";
    std::cin >> I_size; // symbols count
    cout << endl;
    matrix<int> delta(Q_size, I_size); // generated matrix
    std::vector<int> I;
    
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
        try {
            string s;
            cout << "\n\nINPUT STRING: ";
            cin >> s;

            int actual_state = q0;
            for (char c : s) {
                auto it = find(I.begin(), I.end(), c);
                if (it == I.end()) {
                    cout << "BAD_INPUT";
                    continue;
                }
                int index = it - I.begin();
                actual_state = delta(actual_state, index);
                if (actual_state == -1) {
                    cout << "REJECTED\n";
                    continue;
                }
            }

            auto it = find(F.begin(), F.end(), actual_state);
            if (it != F.end()) {
                cout << "ACCEPTED\n";
            } else {
                cout << "REJECTED\n";
            }
        } catch(...) {
            cout << "ERR\n\n";
        }
    }

    return 0;
}