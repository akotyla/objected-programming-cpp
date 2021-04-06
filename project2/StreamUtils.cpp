#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

int GetIntegerFromInterval(int lowerLim, int upperLim) { //sprawdza czy wpisalismy int z odpowiedniego zakresu
    string line = "";

    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;
        int result = 0;

        if(converter >> result) {
            if(lowerLim - 1 < result & result < upperLim + 1)
                return result;
        }
        cout << "Proszę o podanie liczby z zakresu od " << lowerLim << " do " << upperLim << "." << endl;
    }
}

string GetDescription() { //sprawdza czy wpisalismy opis ze zbioru: niesmaczna, znośna, smaczna, pyszna
    string line = "";


    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;
        string result = "";

        if(converter >> result) {
            if(result == "niesmaczna" or result == "znośna" or result == "smaczna" or result == "pyszna")
                return result;
        }
        cout << "Proszę wpisać opis potrawy (niesmaczna, znośna, smaczna, pyszna): ";
    }
}

string GetDifficulty() { //sprawdza czy wpisalismy pozion trudnosci ze zbioru: łatwa, średna, trudna
    string line = "";


    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;
        string result = "";

        if(converter >> result) {
            if(result == "łatwa" or result == "średnia" or result == "trudna")
                return result;
        }
        cout << "Proszę wpisać trudność potrawy (łatwa, średna, trudna): ";
    }
}

string GetString() { //sprawdza czy wpisalismy string
    string line = "";


    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;
        return line;
    }
}

template <typename T>
T GetData(T initialValue, string Exception) { //sprawdza czy wpisalismy double, int lub char
    string line = "";

    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;

        if(converter >> initialValue) {
                return initialValue;
        }
        cout << Exception;
    }
}

