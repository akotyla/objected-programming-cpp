#include <iostream>
#include <string>
#include "CookbookTab.hpp"
#include <fstream>
#include <algorithm>

using namespace std;

CookbookTab::CookbookTab()
{
}

int CookbookTab::getLength()
{
    return cookbookTab.size();
}

void CookbookTab::addCookbookFromFile(const string& file) {
    RecipeTab recipeTab;
    bool x = true;
    ifstream input(file);
    string name, description, level, ingredient, unit, instruction, line, title, skip;
    int preptime, cooktime, amount, i , action = 1;
    double ingredientAmount, portions;
    vector<Ingredient> ingredients;

    getline(input, line, '\0');
    stringstream sstream;
    sstream << line;
    getline(sstream, title);

    while(x) {
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
        //sstream >> skip;
        getline(sstream, skip, '\n');

        //sprawdzenie czy strumień się nie popsuł i czy poziom trudności oraz opis takie jak chcemy
        if((level != "łatwa" & level != "średnia" & level != "trudna") or
            (description != "niesmaczna" & description != "znośna" & description != "smaczna" & description != "pyszna") or !sstream) {
                x = false;
        }

        else {
            recipeTab.addRecipe(Recipe(name, description, preptime, cooktime, portions, level, ingredients, amount, instruction));
            ingredients.clear();
        }
    }

    if(recipeTab.getLength() != 0) {
        recipeTab.titleOfTab = title;
        cookbookTab.push_back(recipeTab);
        cout << "Książka została dodana." << endl;
    }

    else {
        cout << "Niepoprawne dane! Książka nie została dodana." << endl;
    }
}

void CookbookTab::getCookbooks()
{
    if(cookbookTab.size() == 0) cout << "W bazie nie ma książek kucharskich.";
    else {
    cout << "Lista Książek" << endl;
    for (int indx=0; indx<cookbookTab.size(); indx++)
    cout << indx+1 << ". " << cookbookTab[indx].getTitle() << endl;
    }
}

void CookbookTab::getRecipeTab(const string& title)
{
    bool x = false;
    int indx = 0;
    while(not x and indx < cookbookTab.size()) {
        x = (cookbookTab[indx].getTitle() == title);
        indx++;
    }
    if(x) makeAction(cookbookTab[indx - 1]);
    else cout << "W bazie nie ma książki o podanej nazwie." << endl;
}

bool compareCookbooksLexicographically(RecipeTab recipeTab1, RecipeTab recipeTab2) { //porównuje książki wg porządku leksykograficznego
    return recipeTab1.getTitle() < recipeTab2.getTitle();
}

void CookbookTab::sortCookbooksLexicographically() { //sortuje zbiór książek alfabetycznie
    sort(cookbookTab.begin(), cookbookTab.end(), compareCookbooksLexicographically);
}

