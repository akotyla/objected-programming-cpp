#include <string>
#include "Ingredient.cpp"

#ifndef Recipe_hpp
#define Recipe_hpp

using namespace std;

class Recipe
{
    private:
    string nameOfDish;
    string descriptionOfDish;
    int preparationTime;
    double amountOfPortions;
    string difficultyLevel;
    Ingredient listOfIngredients[20];
    int amountOfIngredients;
    string Instruction;

    public:
    Recipe();
    Recipe(string name, string description, int time, double portions, string level, Ingredient ingredients[20], int amount, string instruction);
    void getRecipe();
    string getNameOfRecipe();
    string getLevel();
    void addToFile();
};

#endif
