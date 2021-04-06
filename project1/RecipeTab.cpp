#include <iostream>
#include <string>
#include "RecipeTab.hpp"
#include <fstream>

using namespace std;

RecipeTab::RecipeTab()
{
    ptr = nullptr;
    tab_size = 0;
}

void RecipeTab::addRecipe(const Recipe& recipe)
{
    Recipe* tmp = new Recipe[tab_size + 1];
    for (int i = 0; i < tab_size; i++)
    {
        tmp[i] = ptr[i];
    }
    tmp[tab_size] = recipe;
    delete[] ptr;
    ptr = tmp;
    tab_size++;
}

void RecipeTab::addRecipeFromUser()
{
    string name, description, level, ingredient, unit, instruction;
    int time, i = 0, action = 1;
    double amount, portion;
    Ingredient ingredients[20];

    cout << "Proszę podać nazwę potrawy: ";
    cin.ignore();
    name = GetString();

    cout << "Proszę wybrać opis potrawy (niesmaczna, znośna, smaczna, pyszna): ";
    description = GetDescription();

    cout << "Proszę podać czas przygotowania (w minutach): ";
    time = GetInteger();

    cout << "Proszę podać liczbę porcji: ";
    portion = GetInteger();

    cout << "Proszę wybrać poziom trudności potrawy (łatwa, średnia, trudna): ";
    level = GetDifficulty();

    //wpisywanie listy składników
    while(action == 1)
    {
        cout << "Proszę podać składnik potrawy, ilość oraz jednostkę: " << endl;
        ingredient = GetString();
        amount = GetDouble();
        unit = GetString();

        ingredients[i].setIngredient(ingredient, amount, unit);
        i++;

        cout << "Proszę wybrać akcję." << endl << "1. Dodaj kolejny składnik." << endl << "2. Zakończ dodawanie składników." << endl;
        cout << "Proszę podać numer akcji.";

        action = GetIntegerFrom1To2();
    }

    cout << "Proszę podać instrukcję przygotowania potrawy. Aby zakończyć wprowadzanie przepisu proszę nacisnąć ENTER." << endl;
    cin.ignore();
    getline(cin, instruction);
    addRecipe(Recipe(name, description, time, portion, level, ingredients, i, instruction));
}

void RecipeTab::getAllRecipes()
{
    if(tab_size == 0) cout << "W książce nie ma przepisów.";
    else {
    cout << "Lista Przepisów" << endl;
    for (int indx=0; indx<tab_size; indx++)
    cout << indx+1 << ". " << ptr[indx].getNameOfRecipe() << endl;
    }
}

void RecipeTab::getRecipesByLetter(const char& letter)
{
    int i = 0, action;
    for (int indx=0; indx<tab_size; indx++) {
      if(ptr[indx].getNameOfRecipe()[0] == letter) {
        cout << indx+1 << ". " << ptr[indx].getNameOfRecipe() << endl;;
        i++;
        }
    }
    if(i == 0) {
      cout << "W książce nie ma potrawy, której nazwa rozpoczyna się na " << letter << "." << endl;
    }
}

void RecipeTab::saveToFile(const string& name)
{
    int i = 0;
    for (int indx=0; indx<tab_size; indx++) {
      if(ptr[indx].getNameOfRecipe() == name) {
        ptr[indx].addToFile();
        i++;
        cout << "Plik został utworzony." << endl;
        }
    }
    if(i == 0) cout << "W książce nie ma przepisu o podanej nazwie.";
}

void RecipeTab::getRecipesByLevel(const string& level)
{
    int i = 0, action;
    for (int indx=0; indx<tab_size; indx++) {
      if(ptr[indx].getLevel() == level) {
      cout << indx+1 << ". " << ptr[indx].getNameOfRecipe() << endl;
      i++;
      }
    }
    if(i == 0) {
      cout << "W książce nie ma potrawy o poziomie trudności " << level << "." << endl;
    }
}

void RecipeTab::getRecipesByName(const string& name)
{   int i = 0;
    for (int indx=0; indx<tab_size; indx++) {
      if(ptr[indx].getNameOfRecipe() == name) {
      ptr[indx].getRecipe();
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
    int time, amount, i , action = 1;
    double ingredientAmount, portions;
    Ingredient ingredients[20];

    getline(input, line, '\0');

    stringstream sstream;
    sstream << line;
    getline(sstream, name);
    sstream >> description;
    sstream >> time;
    sstream >> portions;
    sstream >> level;
    sstream >> amount;

    for(i=0; i<amount; i++) { //wprowadzanie listy składników
        sstream >> ingredient;
        sstream >> ingredientAmount;
        sstream >> unit;
        ingredients[i].setIngredient(ingredient, ingredientAmount, unit);
    }

    getline(sstream, instruction, '\0');

    //sprawdzenie czy strumień się nie popsuł i czy poziom trudności oraz opis takie jak chcemy
    if((level != "łatwa" & level != "średnia" & level != "trudna") or
       (description != "niesmaczna" & description != "znośna" & description != "smaczna" & description != "pyszna") or !sstream) {
            cout << "Niewłaściwe dane przepisu.";
    }

    else {
        addRecipe(Recipe(name, description, time, portions, level, ingredients, amount, instruction));
        cout << "Przepis został dodany do książki.";
    }
}


