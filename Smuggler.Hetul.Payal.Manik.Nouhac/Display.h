// Smuggler.Hetul.Payal.Manik.Nouhac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "City.h"
#include "User.h"
#include "Item.h"

#include <iostream>
#include <vector>


using namespace std;

class Display {
    private :   

        vector<City*> cities;
        string userName = "";

        bool loginChecker = false;
    public :
        User u1;
        bool smugglerMenu();

        void citiesMenu();

        void menu();

        vector<City*> getCities();
        
        void addCity(City* c);

        void setCities(vector<City*> c);

        string getUserName();

        void setUserName(string uName);

       /* User getUser();

        void setUser();*/

        bool getLoginChecker();

        void setLoginChecker(bool lChecker);
};


#endif // !"_DISPLAY_H_"


 

