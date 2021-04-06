#include <string>

#ifndef Ingredient_hpp
#define Ingredient_hpp

using namespace std;

class Ingredient {
private:
public:
    Ingredient();
    Ingredient(string name, double amount, string unit);
    string nameOfIngredient;
    double amountOfIngredient;
    string unitOfIngredient;
    void getIngredient();
};

#endif
