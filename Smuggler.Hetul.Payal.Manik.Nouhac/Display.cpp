// Smuggler.Hetul.Payal.Manik.Nouhac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Display.h"
#include "City.h"
#include "User.h"
#include "Item.h"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

bool Display::checkInt(float x) {
    while (cin.fail() || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(512, '\n');
        return true;
    }
    return false;
}


bool Display::smugglerMenu(){
    //user initialization
    int ans = 0;
    if (u1.getName() == "") {
        Item* iu1 = new Item("lsd", 10, 200000);
        Item* iu2 = new Item("weed", 15, 30);
        Item* iu3 = new Item("heroin", 30, 50);
        cout << "Enter the name of the Smuggler : \n";
        cin >> userName;

        u1 = User(userName, cities);

        vector<Item*> lui;
        
        lui = { iu1, iu2, iu3 };
        u1.setInventories(lui);
        
     
    }
    system("cls");
    cout << "#######################\n";
    cout << "user menu :" << "\n";
    cout << "1. To access User Menu.\n";
    cout << "2. To go to Main Page.\n";
    cout << "#######################\n";

    bool checker = true;
    do {
        try {
            checker = false;
            cout << "Please enter the value :\n";
            cin >> ans;
            
            if (checkInt(ans)) throw 10;
            if (ans < 1 || ans > 2) throw 20;
        }
        catch (...) {

            checker = true;
            cout << "#########################\n";
            cout << "Please enter valid input!\n";
            cout << "#########################\n";
        }
    } while (checker);
    switch (ans) {
        case 1: 
            u1.userMenu();
            break;
        case 2:
            return false;
    }
    
    //u1.setInventories();

    return u1.getGameLose();

}

void Display::citiesMenu() {
    int ans = 0;
    int i = 0;
    cout << "Cities data : \n";
    for (i; i < cities.size(); i++) {
        cout << i + 1 << ". " << cities.at(i)->getCityName() << ".\n";
    }
    cout << i + 1 << ". To go to main page.\n";

    bool checker = true;
    do {
        try {
            checker = false;
            cout << "Please enter the number to access specific city menu : \n";
            cin >> ans;
            
            if (checkInt(ans)) throw 10;
            if (ans < 1 || ans > i+1) throw 20;
        }
        catch (...) {

            checker = true;
            cout << "#########################\n";
            cout << "Please enter valid input!\n";
            cout << "#########################\n";
        }
    } while (checker);
    if (ans == i + 1) {
        return;
    }
    
    cities.at(ans-1)->cityMenu();
    
}

void Display::menu() {
    int a = 0;
    system("cls");
    
    
    
    if(loseStatus){

        cout << "#####################\n";
        cout << "##### GAME OVER #####\n";
        cout << "#####################\n";
        loseStatus = false;
    }
    if (loginChecker) {
        cout << "###########################\n";
        cout << "###########################\n";
        cout << "Welcome to Merchant Game : \n\n";
        cout << "###########################\n";

    }
    else
        cout << "Welcome to Main Page: \n\n";
    cout << "1. To access cities : \n";
    cout << "2. To access Smuggler account : \n";

    bool checker = true;
    do {
        try {
            checker = false;
            cout << "please enter number to play game : \n";
            cin >> a;
            if (checkInt(a)) throw 10;
            if (a < 1 || a > 2) throw 20;
        }
        catch (...) {
            
            checker = true;
            cout << "#########################\n";
            cout << "Please enter valid input!\n";
            cout << "#########################\n";
        }
    } while (checker);
    switch (a) {
        case 1:
            citiesMenu();
            break;
        case 2: 
            loseStatus = smugglerMenu();
            if (loseStatus) {
                u1.setName("");
                
            }
            break;

    }
    loginChecker = true;
    menu();
}


vector<City*> Display::getCities() {
    return cities;
}
void Display::addCity(City* c) {
    cities.push_back(c);
}

void Display::setCities(vector<City*> c) {
    cities = c;
}

string Display::getUserName() {
    return userName;
}

void Display::setUserName(string uName) {
    userName = uName;
}


bool Display::getLoginChecker() {
    return loginChecker;
}

void Display::setLoginChecker(bool lChecker) {
    loginChecker = lChecker;
}
