#include <string>
#include "interfaceForRecipeTab.cpp"
#ifndef CookbookTab_hpp
#define CookbooTab_hpp

using namespace std;

class CookbookTab {
  private:
  vector<RecipeTab> cookbookTab;

  public:
  CookbookTab();
  int getLength();
  void addCookbookFromFile(const string& file);
  void getCookbooks();
  void getRecipeTab(const string& title);
  void sortCookbooksLexicographically();
};

#endif
