#include <iostream>
//#include <string>
#include "RecipeTab.hpp"
#include <fstream>
#include <algorithm>

using namespace std;

RecipeTab::RecipeTab() {
}

void RecipeTab::addRecipe(const Recipe& recipe) {
    recipeTab.push_back(recipe);
}

void RecipeTab::setTitle(const string& title) {
    titleOfTab = title;
}

string RecipeTab::getTitle() {
    return titleOfTab;
}

void RecipeTab::addRecipeFromUser() {
    string name, description, level, ingredient, unit, instruction;
    int preptime, cooktime, i = 0, action = 1;
    double amount, portion;
    vector<Ingredient> ingredients;

    cout << "Proszę podać nazwę potrawy: ";
    name = GetString();

    cout << "Proszę wybrać opis potrawy (niesmaczna, znośna, smaczna, pyszna): ";
    description = GetDescription();

    cout << "Proszę podać czas przygotowania (w minutach): ";
    preptime = GetData<int>(0, "Proszę o podanie liczby: ");

    cout << "Proszę podać czas gotowania (w minutach): ";
    cooktime = GetData<int>(0, "Proszę o podanie liczby: ");

    cout << "Proszę podać liczbę porcji: ";
    portion = GetData<int>(0, "Proszę o podanie liczby: ");

    cout << "Proszę wybrać poziom trudności potrawy (łatwa, średnia, trudna): ";
    level = GetDifficulty();

    //wpisywanie listy składników
    while(action == 1) {
        cout << "Proszę podać składnik potrawy, ilość oraz jednostkę: " << endl; //może najpierw składnik, potem ilość, potem jednostkę
        ingredient = GetString();
        amount = GetData<double>(0, "Proszę o podanie liczby: ");
        unit = GetString();

        ingredients.push_back(Ingredient(ingredient, amount, unit));
        i++;

        cout << "Proszę wybrać akcję." << endl << "1. Dodaj kolejny składnik." << endl << "2. Zakończ dodawanie składników." << endl;
        cout << "Proszę podać numer akcji.";

        action = GetIntegerFromInterval(1, 2);
    }

    cout << "Proszę podać instrukcję przygotowania potrawy. Aby zakończyć wprowadzanie przepisu proszę nacisnąć ENTER." << endl;
    cin.ignore();
    getline(cin, instruction);
    addRecipe(Recipe(name, description, preptime, cooktime, portion, level, ingredients, i, instruction));
}

void RecipeTab::getAllRecipes() {
    if(recipeTab.size() == 0) cout << "W książce nie ma przepisów.";
    else {
        cout << "Lista Przepisów" << endl;
        for (int indx=0; indx<recipeTab.size(); indx++)
        cout << indx+1 << ". " << recipeTab[indx].getNameOfRecipe() << endl;
    }
}

int RecipeTab::getLength() {
    return recipeTab.size();
}

void RecipeTab::getRecipesByLetter(const char& letter) {
    int i = 0, action;
    for (int indx=0; indx<recipeTab.size(); indx++) {
      if(recipeTab[indx].getNameOfRecipe()[0] == letter) {
        cout << indx+1 << ". " << recipeTab[indx].getNameOfRecipe() << endl;;
        i++;
        }
    }
    if(i == 0) {
      cout << "W książce nie ma potrawy, której nazwa rozpoczyna się na " << letter << "." << endl;
    }
}


void RecipeTab::saveToFile(const string& name) {
    int i = 0;
    for (int indx=0; indx<recipeTab.size(); indx++) {
      if(recipeTab[indx].getNameOfRecipe() == name) {
        recipeTab[indx].addToFile();
        i++;
        cout << "Plik został utworzony." << endl;
        }
    }
    if(i == 0) cout << "W książce nie ma przepisu o podanej nazwie.";
}

void RecipeTab::getRecipesByLevel(const string& level) {
    int i = 0; //action;
    for (int indx=0; indx<recipeTab.size(); indx++) {
      if(recipeTab[indx].getLevel() == level) {
      cout << indx+1 << ". " << recipeTab[indx].getNameOfRecipe() << endl;
      i++;
      }
    }
    if(i == 0) {
      cout << "W książce nie ma potrawy o poziomie trudności " << level << "." << endl;
    }
}

void RecipeTab::getRecipesByName(const string& name)
{   int i = 0;
    for (int indx=0; indx<recipeTab.size(); indx++) {
      if(recipeTab[indx].getNameOfRecipe() == name) {
      recipeTab[indx].getRecipe();
      i++;
      }
    }
    if(i == 0) {
        cout << "W książce nie ma potrawy o podanej nazwie." << endl;
      }
}

void RecipeTab::addFromFile(const string& file) {

    ifstream input(file);
    string name, description, level, ingredient, unit, instruction, line;
    int preptime, cooktime, amount, i , action = 1;
    double ingredientAmount, portions;
    vector<Ingredient> ingredients;

    getline(input, line, '\0');

    stringstream sstream;
    sstream << line;
    getline(sstream, name);
    sstream >> description;
    sstream >> preptime;
    sstream >> cooktime;
    sstream >> portions;
    sstream >> level;
    sstream >> amount;

    for(i=0; i<amount; i++) { //wprowadzanie listy składników
        sstream >> ingredient;
        sstream >> ingredientAmount;
        sstream >> unit;
        ingredients.push_back(Ingredient(ingredient, ingredientAmount, unit));
    }

    getline(sstream, instruction, '*');

    //sprawdzenie czy strumień się nie popsuł i czy poziom trudności oraz opis takie jak chcemy
    if((level != "łatwa" & level != "średnia" & level != "trudna") or
       (description != "niesmaczna" & description != "znośna" & description != "smaczna" & description != "pyszna") or !sstream) {
            cout << "Niewłaściwe dane przepisu.";
    }

    else {
        addRecipe(Recipe(name, description, preptime, cooktime, portions, level, ingredients, amount, instruction));
        cout << "Przepis został dodany do książki.";
    }
}

void RecipeTab::getFastestRecipe() {
    if(recipeTab.size() == 0) cout << "W książce nie ma przepisów.";
    else {
        sort(recipeTab.begin(), recipeTab.end());
        recipeTab[0].getRecipe();
    }
}

void RecipeTab::sortByFullPreparationTime() {
    sort(recipeTab.begin(), recipeTab.end());
}

bool compareAmountOfIngredients(Recipe recipe1, Recipe recipe2) {
    return recipe1.amountOfIngredients < recipe2.amountOfIngredients;
}

void RecipeTab::sortByAmountOfIngredients() {
    sort(recipeTab.begin(), recipeTab.end(), compareAmountOfIngredients);
}

void RecipeTab::getLeastIngredientsRecipes() { //wyszukuje przepis o najmniejszej liczbie składników
    if(recipeTab.size() == 0) cout << "W książce nie ma przepisów.";
    else
    {
        sort(recipeTab.begin(), recipeTab.end(), compareAmountOfIngredients);
        int i = 0;
        while(recipeTab[i].amountOfIngredients == recipeTab[i+1].amountOfIngredients) {
            recipeTab[i].getRecipe();
            i ++;
        }
        recipeTab[i].getRecipe();
    }
}

bool compareRecipesLexicographically(Recipe recipe1, Recipe recipe2) { //porównuje przepisy wg porządku leksykograficznego
    return recipe1.getNameOfRecipe() < recipe2.getNameOfRecipe();
}

void RecipeTab::sortLexicographically() {
    sort(recipeTab.begin(), recipeTab.end(), compareRecipesLexicographically);
}

