#include <iostream>
#include <string>
#include "Recipe.hpp"
#include <fstream>

using namespace std;

Recipe::Recipe() {
}

Recipe::Recipe(string name, string description, int time, double portions, string level, Ingredient ingredients[20], int amount, string instruction)
{
    nameOfDish = name;
    descriptionOfDish = description;
    preparationTime = time;
    amountOfPortions = portions;
    difficultyLevel = level;

    //dodawanie kolejnych składników
    for(int i=0;i<20;i++) {
    	listOfIngredients[i].setIngredient(ingredients[i].nameOfIngredient, ingredients[i].amountOfIngredient, ingredients[i].unitOfIngredient);
    }
    amountOfIngredients = amount;
    Instruction = instruction;
};

void Recipe::getRecipe() {
    cout << "Szczegóły przepisu " << nameOfDish << endl;
    cout << "Opis: " << descriptionOfDish << endl;
    cout << "Czas przygotowania (w minutach): " << preparationTime << endl;
    cout << "Liczba porcji: " << amountOfPortions << endl;
    cout << "Poziom trudności: " << difficultyLevel << endl;
    cout << "Skladniki: " << endl;
    for(int indx=0; indx<amountOfIngredients; indx++) {
        listOfIngredients[indx].getIngredient();
    }
    cout << "Instrukcja przygotowania: " << Instruction << endl;
};

string Recipe::getNameOfRecipe()
{
    return nameOfDish;
};

string Recipe::getLevel()
{
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
