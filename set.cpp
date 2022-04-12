#include <set>
#include <iostream>

using namespace std;

namespace examples {
    void master_function() {
        set<int> s0; // empty set
        set<int> s1 = {6, 10, 5, 1}; // defined with values

        // the elements are stored in SORTED order and have UNIQUE values
        // the values are IMMUTABLE, you must remove an element and add a modified one if you need to do so

        // insert in random order
        s0.insert(10);
        s0.insert(5);
        s0.insert(8);
        s0.insert(1);
        s0.insert(6);

        s0.insert(10); // duplicated value, nothing happens


        set<int, greater<int>>::iterator itr;
        std::cout << "Set s0:\n";
        for (itr = s0.begin(); itr != s0.end(); ++itr) {
            std::cout << *itr << ' ';
        }
        cout << endl;

        s0.erase(5); // remove the element

        s0.lower_bound(5); // returns an iterator to the first element >= 5 (in this case 8)
        s0.upper_bound(5); // returns an iterator to the first element <= 5 (in this case 1)
    }
}