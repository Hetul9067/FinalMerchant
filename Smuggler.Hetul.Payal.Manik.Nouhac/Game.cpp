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


using namespace std;

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
