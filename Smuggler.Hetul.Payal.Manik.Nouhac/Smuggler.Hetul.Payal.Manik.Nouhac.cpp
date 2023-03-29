// Smuggler.Hetul.Payal.Manik.Nouhac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "City.h"
#include "User.h"
#include "Item.h"

#include <iostream>
#include <vector>

using namespace std;

vector<City*> cities;
string userName = "";

User u1;
bool loginChecker = false;
Item iu1("lsd", 10, 200000);
Item iu2("weed", 15, 30);
Item iu3("heroin", 30, 50);



static bool smugglerMenu(){
    //user initialization
    int ans = 0;
    if (u1.getName() == "") {
        
        cout << "Enter the name of the Smuggler : \n";
        cin >> userName;

        u1 = User(userName, cities);

        /*Item iu1("lsd", 10, 200000);
        Item iu2("weed", 15, 30);
        Item iu3("heroin", 30, 50);
*/

        vector<Item*> lui;
        cout << "hello this is the information regarding to user;" << "\n";
        lui = { &iu1, &iu2, &iu3 };
        u1.setInventories(lui);
        cout << "hello  check over here @@@@@@@@@@@@@@@@@" <<u1.getInventories()[0]->getItemName() << "\n";
        cout << "hello  check over here @@@@@@@@@@@@@@@@@" <<u1.getInventories()[1]->getItemName() << "\n";
       //u1.getInventories()[0]->setName("lsd");
       // u1.getInventories()[1]->setName("weed");
    //u1.getInventories()[2]->setName("heroin");
    }

    cout << "hello  check over here @@@@@@@@@@@@@@@@@" << u1.getInventories()[0]->getItemName() << "\n";
    cout << "hello  check over here @@@@@@@@@@@@@@@@@" << u1.getInventories()[1]->getItemName() << "\n";
    cout << "user menu ^^^^^^" << "\n";
    cout << "1. To access User Menu.\n";
    cout << "2. To go to Main Page.\n";
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

static void citiesMenu() {
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
    cout << "ans " << ans << "\n";
    cities.at(ans-1)->cityMenu();
    
}

static void menu() {
    int a = 0;
    if (loginChecker)
        cout << "Welcome to Merchant Game : \n\n";
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
int main()
{



    //list of cities
    
    cities.push_back(new City("Montreal"));
    cities.push_back(new City("Toronto"));
    cities.push_back(new City("Vancouver"));


    //city initialization
    
    //items initialization for cities
    
    //montreal's item
    Item im1("lsd", 10, 20);
    Item im2("weed", 15, 40);
    Item im3("heroin", 30, 50);
    

    vector<Item*> l1;
    l1 = { &im1, &im2, &im3 };
    cities.at(0)->setInventroies(l1);


    //cities[0]->cityMenu();

    //Toronto's item
    Item it1("lsd", 10, 20);
    Item it2("weed", 15, 30);
    Item it3("heroin", 30, 50);
    Item it4("Cocaine", 10, 20);

    vector<Item*> l2;
    l2 = { &it1, &it2, &it3, &it4 };
    cities[1]->setInventroies(l2);


    //cities[1]->cityMenu();


    //Vancouver's item
    Item iv1("lsd", 10, 20);
    Item iv2("Weed", 15, 30);
    Item iv3("Heroin", 30, 50);
    Item iv4("Cocaine", 10, 20);
    Item iv5("Cetamine", 20, 20);


    vector<Item*> l3;
    l3 = { &iv1, &iv2, &iv3, &iv4, &iv5 };
    cities[2]->setInventroies(l3);


    //cities[2]->cityMenu();

    
   

    /*
    //user initialization
    Item iu1("lsd", 10, 20);
    Item iu2("weed", 15, 30);
    Item iu3("heroin", 30, 50);

    
    vector<Item> lui;
    cout << "hello this is the information regarding to user;" << "\n";
    lui = { iu1, iu2, iu3 };
    u1.setInventories(lui);
    cout << "user menu ^^^^^^" << "\n";
    u1.userMenu();
    cout << "user menu ^^^^^^" << "\n";
    //u1.setInventories();


    */
    menu();
    ///*std::cout << "Hello World!\n";*/

    //clean up dynamically allocated memory
    for (auto c : cities) {
        delete c;
    }
    

}
