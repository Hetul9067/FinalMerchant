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
    cout << "Please enter the value :\n";
    cin >> ans;
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
    cout << "Please enter the number to access specific city menu : \n";
    cin >> ans;
    if (ans == i + 1) {
        return;
    }
    
    cities.at(ans-1)->cityMenu();
    
}

void Display::menu() {
    int a = 0;
    system("cls");
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
    cout << "please enter number to play game : \n";
    cin >> a;
    switch (a) {
        case 1:
            citiesMenu();
            break;
        case 2: 
            bool loseStatus = smugglerMenu();
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