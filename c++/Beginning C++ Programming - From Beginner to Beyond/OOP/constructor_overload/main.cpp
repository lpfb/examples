#include <iostream>
#include <string>
#include "player.h"

using namespace std;

int main() {
    Player hero;
    Player hero2 {"Hero2"};
    Player hero3 {"Hero3", 100, 3};

    cout << "Obj one" << endl;
    cout << "Name: " << hero.get_name() << endl;
    cout << "Health: " << hero.get_health() << endl;
    cout << "Xp: " << hero.get_xp() << endl << endl;

    cout << "Obj two" << endl;
    cout << "Name: " << hero2.get_name() << endl;
    cout << "Health: " << hero2.get_health() << endl;
    cout << "Xp: " << hero2.get_xp() << endl << endl;

    cout << "Obj thress" << endl;
    cout << "Name: " << hero3.get_name() << endl;
    cout << "Health: " << hero3.get_health() << endl;
    cout << "Xp: " << hero3.get_xp() << endl;

    return 0;
}
