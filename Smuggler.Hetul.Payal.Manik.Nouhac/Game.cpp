#include "Display.h"
#include "City.h"
#include "User.h"
#include "Item.h"

#include <iostream>
#include <vector>

using namespace std;


int main()
{



    //list of cities
    Display d1 = Display();

    d1.addCity(new City("Montreal"));
    d1.addCity(new City("Toronto"));
    d1.addCity(new City("Vancouver"));
    
    

    //Montreal's Items
    Item im1("Lsd", 10, 20);
    Item im2("Weed", 15, 40);
    Item im3("Heroin", 30, 50);


    vector<Item*> l1;
    l1 = { &im1, &im2, &im3 };
    d1.getCities().at(0)->setInventroies(l1);


    //cities[0]->cityMenu();

    //Toronto's item
    Item it1("Lsd", 10, 20);
    Item it2("Weed", 15, 30);
    Item it3("Heroin", 30, 50);
    Item it4("Cocaine", 10, 20);

    vector<Item*> l2;
    l2 = { &it1, &it2, &it3, &it4 };
    d1.getCities()[1]->setInventroies(l2);


    //cities[1]->cityMenu();


    //Vancouver's item
    Item iv1("Lsd", 10, 20);
    Item iv2("Weed", 15, 30);
    Item iv3("Heroin", 30, 50);
    Item iv4("Cocaine", 10, 20);
    Item iv5("Cetamine", 20, 20);


    vector<Item*> l3;
    l3 = { &iv1, &iv2, &iv3, &iv4, &iv5 };
    d1.getCities()[2]->setInventroies(l3);


    d1.menu();
   
    
    for (auto c : d1.getCities()) {
        delete c;
    }


}
