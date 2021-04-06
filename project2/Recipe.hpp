//#include <string>
#include <vector>
#include "Ingredient.cpp"

#ifndef Recipe_hpp
#define Recipe_hpp

using namespace std;

class Recipe {
    private:
    string nameOfDish;
    string descriptionOfDish;
    int preparationTime;
    int cookingTime;
    double amountOfPortions;
    string difficultyLevel;
    vector<Ingredient> listOfIngredients;
    string Instruction;

    public:
    Recipe();
    Recipe(string name, string description, int preptime, int cooktime, double portions, string level, vector<Ingredient> ingredients, int amount, string instruction);
    void getRecipe();
    int amountOfIngredients;
    string getNameOfRecipe();
    string getLevel();
    void addToFile();
    bool operator<(const Recipe& recipe) const;
};

#endif
