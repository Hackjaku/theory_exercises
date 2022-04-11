#include <iostream>
#include <vector>

using namespace std;

/*
    this recognize the languages in the form w w'
    where w is a word on the alphabet {a, b} and w' is a copy of w with all the a OR all the b removed
*/

int main() {
    string input;
    std::vector<char> tape;
    cin >> input;
    auto c = input[input.size() - 1];

    bool trailing_characters = true;
    for (int i = input.size() -1; i >= 0; --i) {
        if (trailing_characters && input[i] != c) {
            trailing_characters = false;
        } else if (trailing_characters && input[i] == c) {
            tape.push_back(c);
        } else if (!trailing_characters && input[i] == c) {
            tape.pop_back();
        }
    }
    if (trailing_characters || tape.size() % 2 == 0) {
        cout << "ACCEPTED\n";
    } else {
        cout << "REJECTED\n";
    }

    return 0;
}