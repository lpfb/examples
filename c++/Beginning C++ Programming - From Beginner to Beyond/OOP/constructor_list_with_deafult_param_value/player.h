#include <iostream>
#include <string>

class Player{
    //Attributes
    private:
        std::string name;
        int health;
        int xp;

    public:
        Player(std::string name_val = "none", int health_val = 0, int xp_val = 0)
            : name{name_val}, health{health_val}, xp{xp_val} {
            // Constructor body
            std::cout << "Constructor called" << std::endl;
        };

        // Methods
        void set_name(std::string new_name);
        std::string get_name();

        void set_health(int new_health);
        int get_health();

        void set_xp(int new_xp);
        int get_xp();
};
