#include <iostream>
//#include <string>
#include "Recipe.hpp"
#include <fstream>

using namespace std;

Recipe::Recipe() {
}

Recipe::Recipe(string name, string description, int preptime, int cooktime, double portions, string level, vector<Ingredient> ingredients, int amount, string instruction) {
    nameOfDish = name;
    descriptionOfDish = description;
    preparationTime = preptime;
    cookingTime = cooktime;
    amountOfPortions = portions;
    difficultyLevel = level;

    //dodawanie kolejnych składników
    for(int i=0; i<ingredients.size(); i++) {
    	listOfIngredients.push_back(ingredients[i]);
    }
    amountOfIngredients = ingredients.size();
    Instruction = instruction;
};

void Recipe::getRecipe() {
    cout << "Szczegóły przepisu " << nameOfDish << endl;
    cout << "Opis: " << descriptionOfDish << endl;
    cout << "Czas przygotowania (w minutach): " << preparationTime << endl;
    cout << "Czas gotowania (w minutach): " << cookingTime << endl;
    cout << "Liczba porcji: " << amountOfPortions << endl;
    cout << "Poziom trudności: " << difficultyLevel << endl;
    cout << "Skladniki: " << endl;
    for(int indx=0; indx<amountOfIngredients; indx++) {
        listOfIngredients[indx].getIngredient();
    }
    cout << "Instrukcja przygotowania: " << Instruction << endl;
};

string Recipe::getNameOfRecipe() {
    return nameOfDish;
};

string Recipe::getLevel() {
    return difficultyLevel;
}


void Recipe::addToFile() {
    ofstream file(nameOfDish+".txt");
    streambuf* strm = cout.rdbuf();

    //przekierowanie cout z konsoli do utworzonego wyżej pliku
    cout.rdbuf(file.rdbuf());
    getRecipe();

    //powrót do wyświetlania cout na konsoli
    cout.rdbuf(strm);
}

bool Recipe::operator<(const Recipe& recipe) const {
    int fullTime = (*this).preparationTime + (*this).cookingTime;
    return fullTime < (recipe.preparationTime + recipe.cookingTime);
}



