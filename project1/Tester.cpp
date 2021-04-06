#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;

int GetIntegerFrom1To5() { //sprawdza czy wpisalismy int z zakresu 1-5
    string line = "";

    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;
        int result = 0;

        if(converter >> result) {
            if(0 < result & result < 6)
                return result;
        }
        cout << "Proszę o podanie liczby z zakresu od 1 do 5: ";
    }
}

int GetIntegerFrom1To2() { //sprawdza czy wpisalismy int z zakresu 1-2
    string line = "";


    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;
        int result = 0;

        if(converter >> result) {
            if(0 < result & result < 3)
                return result;
        }
        cout << "Proszę o podanie liczby z zakresu od 1 do 2: ";
    }
}

int GetIntegerFrom1To3() { //sprawdza czy wpisalismy int z zakresu 1-2
    string line = "";


    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;
        int result = 0;

        if(converter >> result) {
            if(0 < result & result < 4)
                return result;
        }
        cout << "Proszę o podanie liczby z zakresu od 1 do 3: ";
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

int GetInteger() { //sprawdza czy wpisalismy int
    string line = "";

    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;
        int result = 0;

        if(converter >> result) {
                return result;
        }
        cout << "Proszę o podanie liczby: ";
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

double GetChar() { //sprawdza czy wpisalismy char
    string line = "";

    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;
        char result = ' ';

        if(converter >> result) {
                return result;
        }
        cout << "Proszę o podanie litery: ";
    }
}

double GetDouble() { //sprawdza czy wpisalismy double
    string line = "";

    while(true) {
        getline(cin, line);
        stringstream converter;
        converter << line;
        double result = 0;

        if(converter >> result) {
                return result;
        }
        cout << "Proszę o podanie liczby: ";
    }
}

