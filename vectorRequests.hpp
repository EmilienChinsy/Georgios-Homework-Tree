#include <vector>
#include "dishes.hpp"  // Include the Dishes class header

typedef struct node {
    Dishes dish;
    struct node* leftChild;
    struct node* rightChild;
} Node;

Node* healthTree = NULL;
Node* ratingTree = NULL;

// Function to add a new dish
void addDish(vector<Dishes>& allDishes) {
    string name;
    string link;
    int healthValue;
    int rating;
    cout << "Enter dish name: ";
    cin.ignore(); // Clear the newline character from input
    getline(std::cin, name); // this allow the user to be able to write whitespaces without issues
    cout << "Enter recipe link: ";
    getline(std::cin, link);
    cout << "Enter health value (1-5): ";
    cin >> healthValue;
    cout << "Enter rating (1-5): ";
    cin >> rating;

    Dishes newDish(name, link, healthValue, rating);

    allDishes.push_back(newDish);

    cout << "New dish has been added!" << endl;
}

// This function removes a Dish from the vector
void removeDish(vector<Dishes> &dishes){
    string name;

    cout << "Enter the name of the dish you wish to delete: ";
    cin >> name;

    for (auto currentDish = dishes.begin(); currentDish != dishes.end(); ++currentDish) {
        if (currentDish->getName() == name) {
            dishes.erase(currentDish);
            cout << "Dish deleted successfully!" << endl;
            return;  
        }
    }
    cout << "Dish not found or does not exist." << endl;
}

// This function retrieves a dish from the vector, we use the name of the dish to find it
void retrieveDish(vector<Dishes> &dishes) {
    string name;
    cout << "Enter the name of your dish: ";
    cin >> name;

    for (Dishes &dishes : dishes) {
        if (dishes.getName() == name) {
            dishes.display();
            return;
        }
    }
    cout << "Dish not found.\n";
}