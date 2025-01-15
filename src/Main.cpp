#include <iostream>
#include <vector>
#include <limits>
#include "treeRequests.hpp"

using namespace std;

//gloabl vector to store all dishes
vector<Dishes> allDishes;

int main()
{
    int userInput;
    bool ending;

    cout << "Welcome to your very own dish storing database! But with trees this team" << endl;
    cout << "This database exists to allow you to store your favorite dishes, a link to their recipes, how healthy they are on a scale from 1 to 5 and a rating from 1 to 5 where 1 is unhealthy/terrible and five is very healthy/amazing"<< endl;
    cout << "For now, here are the actions you can take:" << endl;
    cout << "1. Add a dish" << endl;
    cout << "2. Search for a dish by name" << endl;
    cout << "3. Display all dishes sorted by health value" << endl;
    cout << "4. Display all dishes sorted by rating" << endl;
    cout << "5. Display all dishes sorted by the order in which they were added" << endl;
    cout << "6. Remove a dish using it's name" << endl;
    cout << "7. End the program" << endl;
    cout << "Type the number of the action you want to take in the console" << endl;
    ending = false;
    while (!ending) {
        cin >> userInput;

        if (cin.fail()) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input, please enter a number corresponding an action." << endl;
        } else {
            switch (userInput) {
                case 1:
                    addDish(allDishes);  // Add a new dish
                    break;
                case 2:
                    retrieveDish(allDishes);  // Search dish by name
                    break;
                case 3:
                    emptyBSTHealth();
                    for (int i = 0; i < allDishes.size(); i++){
                        insertBSTHealth(allDishes[i]);
                    }
                    cout << "Here are the dishes sorted by health value:" << endl;
                    BSTHealth();
                    break;
                case 4:
                    emptyBSTRating();
                    for (int i = 0; i < allDishes.size(); i++){
                        insertBSTRating(allDishes[i]);
                    }
                    cout << "Here are the dishes sorted by rating:" << endl;
                    BSTRating();
                    break;
                case 5:
                    if (allDishes.size() == 0) {
                        cout << "you have not created any dishes yet" << endl;
                        break;
                    }
                    cout << "Here are the dishes, sorted by time of arrival" << endl;
                    for (auto &currentDish : allDishes)    
                        currentDish.display();
                    break;
                case 6:
                    removeDish(allDishes);
                    break;
                case 7:
                    cout << "Ending the program."<< endl;
                    ending = true;
                    break;
                default:
                    cout << "Please enter a number that corresponding to an action." << endl;
            }
        }
    }
    return 0;
}
