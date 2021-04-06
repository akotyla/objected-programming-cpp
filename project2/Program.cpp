#include <iostream>
#include <string>
#include "interfaceForCookbookTab.cpp"


using namespace std;

int main() {

    CookbookTab cookbookList;
    //cookbookList.addCookbookFromFile("VegetarianCookbook.txt");
    cout << "Witamy w bazie książek kucharskich! :>" << endl;
    makeCookbookListAction(cookbookList);

}
