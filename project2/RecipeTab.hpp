//#include <string>
#include "Recipe.cpp"
#include "StreamUtils.cpp"
#ifndef RecipeTab_hpp
#define RecipeTab_hpp

using namespace std;

class RecipeTab {
  private:
  vector<Recipe> recipeTab;

  public:
  string titleOfTab;
  RecipeTab();
  int getLength();
  void setTitle(const string& title);
  string getTitle();
  void addRecipe(const Recipe& recipe);
  void getAllRecipes(); //wyswietla spis potraw w ksiazce
  void getRecipesByLetter(const char& letter); //wyswietla potrawy na podaną literę
  void getRecipesByLevel(const string& level); //wyswietla potrawy o zadanym poziomie trudnosci
  void getRecipesByName(const string& name); //wyswietla potrawe o podanej nazwie
  void addFromFile(const string& file);
  void addRecipeFromUser(); //dodaje przepis na podstawie danych wprowadzonych przez uzytkownika
  void saveToFile(const string& name);
  void getFastestRecipe(); //wybiera przepis o najkrótszym wspólnym czasie przygotowania i gotowania
  void getLeastIngredientsRecipes(); //wybiera przepis z najmniejszą liczbą składników
  void sortByAmountOfIngredients(); //sortuje wg liczby składników rosnąco
  void sortByFullPreparationTime(); //sortuje wg wspólnego czasu przygotowania i gotowania rosnąco
  void sortLexicographically(); //sortuje wg nazwy alfabetycznie
};

#endif
