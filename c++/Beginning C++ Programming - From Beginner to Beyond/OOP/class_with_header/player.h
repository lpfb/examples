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
