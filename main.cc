#include "models/finite_state.h"
#include "utils/finite_state_utils.h"

using namespace std;
using namespace utils::finite_state;

int main(int argc, char* argv[]) {
    machines::FiniteState fsm;
    int Q_size, I_size;

    Q_size = utils::finite_state::input_states(fsm);
    I_size = utils::finite_state::input_symbols(fsm);
    utils::finite_state::input_relation(fsm, Q_size, I_size);

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