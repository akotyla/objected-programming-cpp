#include <iostream>
//#include <string>

#include "Ingredient.hpp"

using namespace std;

Ingredient::Ingredient() {
}

Ingredient::Ingredient(string name, double amount, string unit)
{
    nameOfIngredient = name;
	amountOfIngredient = amount;
	unitOfIngredient = unit;
};

void Ingredient::getIngredient() {
    cout << "Nazwa składnika: "<< nameOfIngredient << endl;
    cout << "Ilość: " << amountOfIngredient << " " << unitOfIngredient << endl;
}
