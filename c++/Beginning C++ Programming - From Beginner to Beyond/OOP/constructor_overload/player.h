#include <string>

class Player{
    //Attributes
    private:
        std::string name;
        int health;
        int xp;

    public:
        // Constructor
        Player();
        Player(std::string name_val);
        Player(std::string name_val, int health_val, int xp_val);

        // Methods
        void set_name(std::string new_name);
        std::string get_name();

        void set_health(int new_health);
        int get_health();

        void set_xp(int new_xp);
        int get_xp();
};
