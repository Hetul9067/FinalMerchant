#include "User.h"
#include "Item.h"
#include "City.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;


//constructor
User::User() {

}
User::User(string n, vector<City*>& cities) {
	name = n;
	for (int i = 0; i < cities.size(); i++) {
		//City* c = ;
		citiesLi.push_back(new City());
		citiesLi[i]->setCityName(cities[i]->getCityName());
		//cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$";
		citiesLi[i]->setInventroies(cities[i]->getInventories());

	}
	citiesLi = cities;
	randomCityAssigner();
	randomNextCityAssigner();

	/*for (int i = 0; i < currentCity->getInventories().size(); i++) {
		cout << "city name : " << currentCity->getCityName() << "\n";
		
	}*/
}

void User::randomCityAssigner() {
	srand(time(nullptr));
	int ran = rand() % 3;
	
	while (currentCity == NULL || citiesLi[ran] != currentCity) {

		currentCity = citiesLi[rand() % 3];
	}
	cout << "current city name: " << currentCity->getCityName() << "\n";

}
void User::randomNextCityAssigner() {
	//srand(time(nullptr));
	
	srand(randomValue);
	if (randomValue == 1) randomValue = 0;
	else randomValue = 1;

	int ran = rand() % 3;

	do{

		nextCity = citiesLi[rand() % 3];
		
	} while (nextCity == currentCity || nextCity == tempCity);
	//cout << "Next city name: " << nextCity->getCityName() << "\n";
}

void User::inventoriesListDisplay() {
	cout << "################################################################################" << "\n";

	cout << "##### Item\t\t" << "Buying Price\t\t" << "Selling Price\t\t" <<"Quantity\n";
	for (int i = 0; i < inventories.size();i++) {
		cout << "##### " << i+1 << ". " << inventories.at(i)->getItemName() << "\t\t\t|" << inventories[i]->getItemBuyingPrice()
			<< "|\t\t\t|" << inventories.at(i)->getItemSellingPrice() << "|\t\t|" << inventories.at(i)->getItemQuantity() << "|\n";


	}
	
	cout << "################################################################################" << "\n";
	
}

//for selling wares
void User::sellTheirWares() {
	int ans = 0;
	int quantity = 0;
	bool quantityChecker = false;
	float earnedMoney = 0;


	cout << "#############################################################" << "\n";
	cout << "##### Item\t\t" << "Selling Price\t\tQuantity\n";
	for (int i = 0; i < inventories.size();i++) {
		cout << "##### " << i + 1 << ". " << inventories.at(i)->getItemName() << "\t\t\t|" << inventories.at(i)->getItemSellingPrice() <<"|\t\t\t|" << inventories.at(i)->getItemQuantity() <<  "|\n";
	}
	cout << "#############################################################" << "\n";

	//inventoriesListDisplay();
	cout << "Please enter the item number for selling : \n";
	cin >> ans;
	
	do {

		cout << "Please enter the quantities of the "<< inventories[ans-1]->getItemName() <<" : \n";
		cin >> quantity;
		quantityChecker = false;
		if (quantity > inventories[ans-1]->getItemQuantity()) {
			cout << "########################################\n";
			cout << "Sorry, we don't have that much quantity \n";
			quantityChecker = true;
		}
	} while (quantityChecker);

	earnedMoney = quantity * inventories[ans - 1]->getItemSellingPrice();
	cout << "################################";
	cout << "Earned amount : " << earnedMoney << "\n";
	cout << "################################";

	//increasing user's money after selling the item
	userMoney += earnedMoney;

	//decreasing user's item quantity after selling it successfully 
	inventories[ans - 1]->setItemQuantity(inventories[ans - 1]->getItemQuantity() - quantity);
	cout << "going to user menu\n\n\n\n";
	userMenu();
}

void User::buyTheirWares() {
	int ans = 0;
	float quantity = 0;
	bool quantityChecker = false;
	float investedMoney = 0;


	cout << "#############################################################" << "\n";
	for (int i = 0; i < citiesLi.size();i++) {
		cout << "------------------------------------------------";
		cout << "city name : " << citiesLi[i]->getCityName() << "\n";
		cout << "##### Item \t\t\t" << " Price\t\t\tQuantity\n";
		for (int j = 0; j < citiesLi[i]->getInventories().size();j++) {
			cout << "##### " << j + 1 << ". " << citiesLi[i]->getInventories()[j]->getItemName() << "\t\t\t|" << citiesLi[i]->getInventories()[j]->getItemSellingPrice() << "|\t\t\t|"  << citiesLi[i]->getInventories()[j]->getItemQuantity() << "|\n";

		}
		cout << "------------------------------------------------";
	}
	cout << "#############################################################" << "\n";
	cout << "Enter 0 to exit from buying menu : \n";
	
	cout << "Please enter the item number to buy item in " << currentCity->getCityName() << " : \n";
	cin >> ans;
	if (ans == 0) {
		cout << "Thank you for visiting buying menu!";
		return;
	}

	do {

		cout << "Please enter the quantities of the " << currentCity->getInventories()[ans - 1]->getItemName() << " : \n";
		cin >> quantity;
		quantityChecker = false;
		if (quantity > currentCity->getInventories()[ans - 1]->getItemQuantity()) {
			cout << "########################################\n";
			cout << "Sorry, we don't have that much quantity \n";
			quantityChecker = true;
		}
	} while (quantityChecker);



	investedMoney = quantity * currentCity->getInventories()[ans - 1]->getItemSellingPrice();

	if (investedMoney > userMoney) {
		cout << "###################################\n";
		cout << "Sorry! you don't have enough money.\n";
		cout << "###################################\n";
		
			
	}
	else {

		
		//increasing user's item quantity after buying it successfully
		int itemNumber = -1;
		
	
		for (int i = 0; i < inventories.size(); i++) {
			if (inventories[i]->getItemName() == currentCity->getInventories()[ans - 1]->getItemName()) {
				itemNumber = i;
				break;
			}
		}

		
		Item*  it = new Item();
		if (itemNumber == -1) {
			
			it->setName(currentCity->getInventories()[ans -1 ]-> getItemName());
			
			it->randomlySetBuyingPrice(currentCity->getInventories()[ans - 1]->getItemSellingPrice());
			it->randomlySetSellingPrice();
			it->setItemQuantity(0);
			
			inventories.push_back(it);

			itemNumber = inventories.size()-1;

		}
		Item* ite = currentCity->getInventories()[ans - 1];
		ite->setItemQuantity(currentCity->getInventories()[ans - 1]->getItemQuantity() - quantity);
			
		inventories[itemNumber ]->setItemQuantity(inventories[itemNumber ]->getItemQuantity() + quantity);
		
		cout << "################################\n";
		cout << "Total cost : " << investedMoney << "\n";
		cout << "################################";

		//decreasing user's money after buying the item
		userMoney -= investedMoney;

		
		cout << "it's finished\n";

	}
	userMenu();
}

void User::userAnsChecker(int a) {
	switch (a) {
		case 1: 
			sellTheirWares();
			break;
		case 2:
			buyTheirWares();
			break;
		case 3: {
			tempCity = currentCity;
			
			currentCity = nextCity;
			
			
			randomNextCityAssigner();
			
			fineChecker();
			
			if (gameLose) {
				return;
			}
			userMenu();
			break;

		}
		
	}
}

//for printing user menu
void User:: userMenu() {
	system("cls");
	if (caught) {
		cout << "#############################\n";
		cout << "You are caught by the Police!\n";
		cout << "#############################\n";
		caught = false;

	}
	cout << "###########################\n";
	cout << "###########################\n";
	cout << "Welcome to Smuggler Page : \n";
	cout << "###########################\n";
	cout << "Smuggler name : " << name << "\n";
	cout << "User's total money : " << userMoney << "\n";
	cout << "User's current City name : " << currentCity->getCityName() << "\n";
	cout << "-------------------------------------------------------------------\n";
	cout << "After reaching 100% " << name << " is going to caught by the Police\n";
	cout << caughtPercentageCounter << "% chances to be caught by the Police\n";
	cout << "-------------------------------------------------------------------\n";
	
	
	inventoriesListDisplay();

	

	int ans = 0;
	cout << "1. Sell their wares\n";
	cout << "2. Buy their wares\n";
	cout << "3. travel to a new city\n";
	cout << "4. Going back to Main Page\n";
	cout << "Please enter the require option : \n";
	cin >> ans;
	if (ans == 4) return;
	userAnsChecker(ans);
	
				
}

//for randomly assigning the city to user


	
string User:: getName() {
	return name;
}
void User :: setName(string n) {
	name = n;
}
	
vector<Item*> User::  getInventories() {
	return inventories;
}
	
void User :: setInventories(vector<Item*> inv) {
	inventories = inv;
}


float User :: itemQuantitiesChecker() {
	float totalQuantities = 0;
	for (int i = 0; i < inventories.size();i++) {
		totalQuantities += inventories.at(i)->getItemQuantity();
	}
	return totalQuantities;
}
void User::fineChecker() {
	
	float totalQuantity = itemQuantitiesChecker();
	if (totalQuantity >= 8000)
	{
		caughtPercentageCounter += 40;
		cout << caughtPercentageCounter << "percentage of the caught \n";		
	}
	else if (totalQuantity >= 5000) {
		caughtPercentageCounter += 30;
		cout << caughtPercentageCounter << "percentage of the caught \n";

	}
	else if (totalQuantity >= 2000) {
		caughtPercentageCounter += 20;
		cout << caughtPercentageCounter << "percentage of the caught \n";

	}
	else if (totalQuantity >= 500) {
		caughtPercentageCounter += 10;
		cout << caughtPercentageCounter << "percentage of the caught \n";

	}

	if (caughtPercentageCounter >= 100) {
		caught = true;
		caughtPercentageCounter = 0;
		tempCity = currentCity;
		currentCity = nextCity;
		randomNextCityAssigner();
		
		//minimum one item require
		
		if (!inventories.empty()) {
			inventories.pop_back();

		}
		
		userMoney -= fine;
		fine += 50;
		if (userMoney <= 0) {
			gameLose = true;
			cout << "ohh You lose the game!\n";
		
		}
		cout << "user Money is : " << userMoney << "\n";

	}
}
	
