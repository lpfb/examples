#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> vec {1,2,3};

    for (unsigned i {0}; i < vec.size(); ++i) {
        cout << "I: " << i << endl;
        for (unsigned j {i+1}; j < vec.size(); j++) {
            cout << "J: " << j << endl;
        }
    }

    return 0;
}
