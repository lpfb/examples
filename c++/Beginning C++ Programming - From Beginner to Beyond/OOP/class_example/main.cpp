#include <iostream>
#include <string>

class Player{
    //Attributes
    private:
        std::string name;
        int health;
        int xp;
    public:
        void set_name(std::string new_name);
        std::string get_name();
};

void Player::set_name(std::string new_name) {
    name = new_name;
}

std::string Player::get_name() {
    return name;
}

using namespace std;

int main() {
    Player hero;

    hero.set_name("Teste");
    cout << "Hero name: " << hero.get_name() << endl;

    return 0;
}
