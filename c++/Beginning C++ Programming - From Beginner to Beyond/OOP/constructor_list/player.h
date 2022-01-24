#include <iostream>
#include <string>

class Player{
    //Attributes
    private:
        std::string name;
        int health;
        int xp;

    public:
        // Constructor list
        Player()
            : name{"none"}, health{0}, xp{0} {
            std::cout << "No-arg Constructor" << std::endl;
        };

        Player(std::string name_val)
            : name{name_val}, health{0}, xp{0} {
            std::cout << "One-arg Constructor" << std::endl;
        };

        Player(std::string name_val, int health_val, int xp_val)
            : name{name_val}, health{health_val}, xp{xp_val} {
            std::cout << "Three-arg Constructor" << std::endl;
        };

        // Methods
        void set_name(std::string new_name);
        std::string get_name();

        void set_health(int new_health);
        int get_health();

        void set_xp(int new_xp);
        int get_xp();
};
