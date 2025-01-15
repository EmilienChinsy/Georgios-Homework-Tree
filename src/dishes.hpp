#include <string>
#include <iostream>

using namespace std;

class Dishes {
    private:
        string name;
        string link;//link to an online or locally saved recipe.
        int healthValue;
        int rating;
        // this variable is static so that it doesn't disappear, it is here to track the amount of dishes
        static int amount_of_Dishes;
    
    public:
        //Default constructor
        Dishes(): name(""), link(""), healthValue(0), rating(0){
            amount_of_Dishes ++;
        }

        //Constructor with parameter, this one will probably be the only useful one.
        Dishes(string name, string link, int value, int rating)
            : name(name), link(link), healthValue(value), rating(rating) {
                amount_of_Dishes ++;
        }
        
        //Destructor
        ~Dishes() {
            amount_of_Dishes --;
        }

        //Returns the amount of dishes
        static int getAmountOfDishes() {
            return amount_of_Dishes;
        }
        // the other functions will be defined outside of the class itslef for better readability
        // they are defined in the same file, from line 43 onward.
        string getName();
        string getLink();
        int getHealthValue();
        int getRating();
        void setName(string Name);
        void setLink(string Link);
        void setHealthValue(int HealthValue);
        void setRating(int Rating);
        void display();
};

//Get functions also known as getters, their role is to retrieve values or "get" them.
//The thing they will "get" is in their name
string Dishes::getName() {
    return name;
}
string Dishes::getLink(){
    return link;
}
int Dishes::getHealthValue(){
    return healthValue;
}
int Dishes::getRating(){
    return rating;
}

//Set functions also known as setters, their role is to assign values or "set" them.
//The thing they will "set" is in their name
void Dishes::setName(string name) {
    this -> name = name; 
}
void Dishes::setLink(string link){
    this -> link = link;
}
void Dishes::setHealthValue(int healthValue){
    this -> healthValue = healthValue;
}
void Dishes::setRating(int rating){
    this -> rating = rating;
}

//Displays this instance of the class' information.
void Dishes::display() {
    cout << "Name of the dish: " << name << endl;
    cout << "Link to a recipe of the dish: " << link << endl;
    cout << "Health value of the dish: " << healthValue << endl; 
    cout << "Rating of the dish: " << rating << endl;
}

// Initialize the static data which will track the amount of dishes
int Dishes::amount_of_Dishes = 0;