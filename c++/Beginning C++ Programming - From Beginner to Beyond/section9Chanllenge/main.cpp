#include <iostream>
#include <vector>

using namespace std;

int main() {
    char pressedKey;
    vector<int> numbers {};
    int number;

    do {
        cout << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> pressedKey;

        if (pressedKey == 'p' || pressedKey == 'P') {
            cout << "[ ";
            for (auto number: numbers)
                cout << number << " ";
            cout << "]" << endl;

        } else if (pressedKey == 'a' || pressedKey == 'A') {
            cout << "Add an integer to add to the list: ";
            cin >> number;
            numbers.push_back(number);

        } else if (pressedKey == 'm' || pressedKey == 'M') {
            int sum {0};
            double average {0};

            for (auto number: numbers)
                sum += number;

            if (numbers.size() > 0)
                average = static_cast<double>(sum) / numbers.size();

            cout << "The average is: " << average << endl;

        } else if (pressedKey == 'l' || pressedKey == 'L') {
            int largest {(numbers.size() > 0) ? numbers.at(0) : 0};

            for (auto number: numbers) {
                if (number > largest)
                    largest = number;
            }

            cout << "The smallest number is: " << largest << endl;

        } else if (pressedKey == 's' || pressedKey == 'S') {
            int smallest {(numbers.size() > 0) ? numbers.at(0) : 0};

            for (auto number: numbers) {
                if (number < smallest)
                    smallest = number;
            }

            cout << "The smallest number is: " << smallest << endl;
        }

    } while(pressedKey != 'q' && pressedKey != 'Q');

    cout << endl;
    cout << "Goodbye" << endl;

    return 0;
}
