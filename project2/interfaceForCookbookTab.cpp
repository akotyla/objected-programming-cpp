#include <iostream>
#include <cstddef>
#include <string>
#include "CookbookTab.cpp"

using namespace std;

void cookbookMenu() {
    cout << "Proszę wybrać akcję: " << endl;
    cout << "1. Wyświetl spis książek kucharskich." << endl;
    cout << "2. Dodaj książkę kucharską z pliku." << endl;
    cout << "3. Wyjdź." << endl;
}

void makeCookbookListAction(CookbookTab cookbookTab) {
    int action;
    cookbookMenu();
    cout << "Proszę wprowadzić numer wybranej akcji: " << endl;
    action = GetIntegerFromInterval(1, 3); //sprawdzamy, czy podano integer od 1 do 3

    while(action != 3) {
            int option;
            switch(action) {

            //wyświetlanie spisu książek
            case 1: {
                if(cookbookTab.getLength() == 0) cout << "W książce nie ma przepisów.";
                else {

                system("clear");
                cookbookTab.sortCookbooksLexicographically();
                cookbookTab.getCookbooks();
                cout << endl << "Proszę wybrać akcję: " << endl;
                cout << "1. Wyświetl książkę kucharską." << endl;
                cout << "2. Powrót do menu." << endl;
                cout << "Proszę wprowadzić numer wybranej akcji: ";
                option = GetIntegerFromInterval(1, 2);

                switch(option) {
                    case 1: {
                        string title;
                        cout << "Proszę podać nazwę książki: ";
                        title = GetString();
                        system("clear");
                        cookbookTab.getRecipeTab(title);
                        break;
                    }
                }

                }

            }
            break;

            //dodawanie książki
            case 2: {
                system("clear");
                string file;
                cout << "Dodawanie książki kucharskiej." << endl;
                cout << "Proszę podać nazwę pliku." << endl;
                cin >> file;
                cookbookTab.addCookbookFromFile(file);
                cin.get();
            }
            break;
    }
    cout << endl << "Aby powrócić do menu głównego proszę nacisnąć ENTER.";
    cin.get();

    system("clear");
    cookbookMenu();
    cout << "Proszę wprowadzić numer wybranej akcji: " << endl;
    action = GetIntegerFromInterval(1, 3);
    }

    system("clear"); //wykonuje się w przypadku wprowadzenia 3 opuszcza program
    cout << "Dziekujemy za skorzystanie z naszej bazy książek kucharskich!" << endl;
    cout << "Zapraszamy ponownie! :>" << endl;

}
