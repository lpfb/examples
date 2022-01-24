#include <iostream>
#include <string>
#include "player.h"

using namespace std;

int main() {
    Player hero1;
    Player hero2 {"Hero2"};
    Player hero3 {"Hero3", 100, 3};

    Player hero2_copy {hero2}; // Copying hero 2 object
    Player hero3_copy {hero3}; // Copying hero 3 object

    cout << "Obj one" << endl;
    cout << "Name: " << hero1.get_name() << endl;
    cout << "Health: " << hero1.get_health() << endl;
    cout << "Xp: " << hero1.get_xp() << endl << endl;

    cout << "Obj two" << endl;
    cout << "Name: " << hero2.get_name() << endl;
    cout << "Health: " << hero2.get_health() << endl;
    cout << "Xp: " << hero2.get_xp() << endl << endl;

    cout << "Obj three" << endl;
    cout << "Name: " << hero3.get_name() << endl;
    cout << "Health: " << hero3.get_health() << endl;
    cout << "Xp: " << hero3.get_xp() << endl << endl;

    cout << "Obj two copied (constructor not called)" << endl;
    cout << "Name: " << hero2_copy.get_name() << endl;
    cout << "Health: " << hero2_copy.get_health() << endl;
    cout << "Xp: " << hero2_copy.get_xp() << endl << endl;

    cout << "Obj three copied (constructor not called)" << endl;
    cout << "Name: " << hero3_copy.get_name() << endl;
    cout << "Health: " << hero3_copy.get_health() << endl;
    cout << "Xp: " << hero3_copy.get_xp() << endl << endl;

    return 0;
}
