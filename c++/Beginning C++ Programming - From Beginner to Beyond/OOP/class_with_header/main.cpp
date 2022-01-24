#include <iostream>
#include <string>
#include "player.h"

using namespace std;

int main() {
    Player hero;

    hero.set_name("Teste");
    cout << "Hero name: " << hero.get_name() << endl;

    return 0;
}
