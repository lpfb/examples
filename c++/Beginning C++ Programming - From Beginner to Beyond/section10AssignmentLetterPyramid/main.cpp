#include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "Type some characters in order to construct a letter pyramid: ";

    string userString {};
    getline(cin, userString);

    cout << endl;

    size_t witheSpacesCnt = userString.length();
    string pyramidString {};
    string temp {};

    for (size_t i {0}; i < userString.length(); i++) {
        pyramidString += userString.at(i);
        temp = pyramidString;

        // Creating current pyramid string
        for (size_t j {i}; j > 0; j--) {
            temp += userString.at(j-1);
        }

        // Indentation
        for (size_t k {0}; k < (witheSpacesCnt - pyramidString.length()); k++)
            cout << " ";

        cout << temp << endl;
    }
    cout << endl;

    return 0;
}
