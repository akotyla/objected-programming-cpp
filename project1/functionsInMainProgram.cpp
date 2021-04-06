#include <iostream>
#include <cstddef>
#include <string>
#include "RecipeTab.cpp"

using namespace std;


void menu() {
    cout << "Proszę wybrać akcję: " << endl;
    cout << "1. Wyświetl spis przepisów." << endl;
    cout << "2. Dodaj przepis." << endl;
    cout << "3. Zapisz przepis do pliku." << endl;
    cout << "4. Znajdź przepis." << endl;
    cout << "5. Wyjdź." << endl;
}

void RecipeSearch(const int& action, RecipeTab cookbook) {
    switch(action) {
    case 1: {
        string name;
        cout << "Proszę podać nazwę potrawy: ";
        name = GetString();
        system("clear");
        cookbook.getRecipesByName(name);
        break;
    }
    case 2: {
        char letter;
        cout << "Proszę podać literę: ";
        letter = GetChar();
        system("clear");
        cout << "Przepisy na literę " << letter << ": " << endl;
        cookbook.getRecipesByLetter(letter);
        break;
    }
    case 3: {
        string level;
        cout << "Proszę wpisać trudność potrawy (łatwa, średna, trudna): ";
        level = GetDifficulty();
        system("clear");
        cout << "Potrawy o podanej trudności: " << level << ": " << endl;
        cookbook.getRecipesByLevel(level);
        break;
        }
    }
}

void makeAction(RecipeTab cookbook) {

    int action;
    menu();
    cout << "Proszę wprowadzić numer wybranej akcji: " << endl;
    action = GetIntegerFrom1To5(); //sprawdzamy, czy podano integer od 1 do 5

    while(action != 5) {
            int option;
            switch(action) {

            //wyświetlanie spisu potraw
            case 1: {
                system("clear");
                cookbook.getAllRecipes();
                cout << endl << "Proszę wybrać akcję: " << endl;
                cout << "1. Wyświetl przepis." << endl <<"2. Powrót do menu." << endl
                << "Proszę wprowadzić numer wybranej akcji: ";
                option = GetIntegerFrom1To2();

                if(option == 1) {
                    string nameDish;
                    cout << "Proszę podać nazwę potrawy: ";
                    nameDish = GetString();
                    system("clear");
                    cookbook.getRecipesByName(nameDish);
                }

            }
            break;

            //dodawanie przepisu
            case 2: {
                system("clear");
                cout << "Proszę wybrać akcję: " << endl;
                cout << "1. Dodaj przepis ręcznie." << endl;
                cout << "2. Dodaj przepis z pliku." << endl;
                cout << "3. Powrót do menu." << endl;
                option = GetIntegerFrom1To3();

                switch(option) {
                    case 1: {
                        system("clear");
                        cout << "Dodawanie przepisu." << endl;
                        cookbook.addRecipeFromUser();
                        cout << "Przepis został dodany.";
                        break;
                        }
                    case 2: {
                        system("clear");
                        string file;
                        cout << "Dodawanie przepisu." << endl;
                        cout << "Proszę podać nazwę pliku." << endl;
                        cin >> file;
                        cookbook.addFromFile(file);
                        break;
                        }
                    }
                cin.get();
            }
            break;

            case 3: {
            system("clear");
            string name;
            cout << "Proszę podać nazwę potrawy." << endl;
            getline(cin, name);
            cookbook.saveToFile(name);
            break;
            }

            case 4: {
                system("clear");
                int option;
                cout << "Proszę wybrać akcję: " << endl;
                cout << "1. Znajdź przepis o danej nazwie." << endl;
                cout << "2. Znajdź przepis na podaną literę." << endl;
                cout << "3. Znajdź przepis o danym poziomie trudności." << endl;
                cout << "Proszę wprowadzić numer wybranej akcji: ";
                option = GetIntegerFrom1To3();
                RecipeSearch(option, cookbook);
                break;
            }

    }
    cout << endl << "Aby powrócić do menu głównego proszę nacisnąć ENTER.";
    cin.get();

    system("clear");
    menu();
    cout << "Proszę wprowadzić numer wybranej akcji: " << endl;
    action = GetIntegerFrom1To5();
    }

    system("clear"); //wykonuje się w przypadku wprowadzenia 5, opuszcza program
    cout << "Dziekujemy za skorzystanie z naszej książki!" << endl;
    cout << "Zapraszamy ponownie! :>" << endl;

}

