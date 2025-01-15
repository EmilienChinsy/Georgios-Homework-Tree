#include <vector>
#include "vectorRequests.hpp"

// Tree functions from here on out

void emptyBSTHealth(){
    healthTree = NULL;
}

void emptyBSTRating(){
    ratingTree = NULL;
}

void insertBSTHealth(Dishes& newDish){
    Node* newNode = new Node;
    newNode->dish = newDish;  // Use the dish object
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    Node* parent;
    Node* current;

    if(healthTree == NULL){ // tree is empty
        healthTree = newNode;
    }
    else{
        current = healthTree;
        parent = NULL;
        while(true){
            parent = current;

            if(newDish.getHealthValue() < parent->dish.getHealthValue()){ // compare based on health value (or another property)
                current = current->leftChild;
                if(current == NULL){
                    parent->leftChild = newNode;
                    return;
                }
            }
            else {
                current = current->rightChild;

                if(current == NULL){
                    parent->rightChild = newNode;
                    return;
                }
            }
        }
    }
}

void insertBSTRating(Dishes& newDish){
    Node* newNode = new Node;
    newNode->dish = newDish;  // Use the dish object
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    Node* parent;
    Node* current;

    if(ratingTree == NULL){ // tree is empty
        ratingTree = newNode;
    }
    else{
        current = ratingTree;
        parent = NULL;
        while(true){
            parent = current;
            if(newDish.getHealthValue() < parent->dish.getHealthValue()){ // compare based on health value (or another property)
                current = current->leftChild;
                if(current == NULL){
                    parent->leftChild = newNode;
                    return;
                }
            }
            else{
                current = current->rightChild;
                if(current == NULL){
                    parent->rightChild = newNode;
                    return;
                }
            }
        }
    }
}

void inOrderTraversal(Node* root){
    if(root != NULL){
        inOrderTraversal(root->leftChild);
        root->dish.display(); // display the dish data
        inOrderTraversal(root->rightChild);
    }
}

void inOrderStorage(Node* root, std::vector<Dishes>& dishValues)
{
    if(root != NULL)
    {
        inOrderStorage(root->leftChild, dishValues);
        dishValues.push_back(root->dish);  // Store the Dish object
        inOrderStorage(root->rightChild, dishValues);
    }
}

void sortedArrayToBalancedBST(Node*& root, std::vector<Dishes>& dishValues, int start, int end)
{
    if(start > end)
        return;

    int median = (start + end) / 2;
    Node* newNode = new Node;
    newNode->dish = dishValues[median]; // Set the dish object
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    root = newNode;

    sortedArrayToBalancedBST(newNode->leftChild, dishValues, start, median - 1);
    sortedArrayToBalancedBST(newNode->rightChild, dishValues, median + 1, end);
}

void balanceBST(Node*& root)
{
    std::vector<Dishes> dishValuesInOrder;

    inOrderStorage(root, dishValuesInOrder);  // Store Dishes in vector

    delete root;  // Clear the tree before rebuilding

    sortedArrayToBalancedBST(root, dishValuesInOrder, 0, dishValuesInOrder.size() - 1);  // Rebuild the tree with balanced structure
}

void BSTHealth() {
    balanceBST(healthTree);
    inOrderTraversal(healthTree);
    emptyBSTHealth();
}

void BSTRating() {
    balanceBST(ratingTree);
    inOrderTraversal(ratingTree);
    emptyBSTRating();
}
