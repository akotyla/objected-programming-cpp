#include <string>
#include "Recipe.cpp"
#include "Tester.cpp"
#ifndef RecipeTab_hpp
#define RecipeTab_hpp

using namespace std;

class RecipeTab {
  private:
  Recipe* ptr;
  int tab_size;

  public:
  RecipeTab();
  void addRecipe(const Recipe& recipe);
  void getAllRecipes(); //wyswietla spis potraw w ksiazce
  void getRecipesByLetter(const char& letter); //wyswietla potrawy na podaną literę
  void getRecipesByLevel(const string& level); //wyswietla potrawy o zadanym poziomie trudnosci
  void getRecipesByName(const string& name); //wyswietla potrawe o podanej nazwie
  void addFromFile(const string& file);
  void addRecipeFromUser(); //dodaje przepis na podstawie danych wprowadzonych przez uzytkownika
  void saveToFile(const string& name);

};

#endif
