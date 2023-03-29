#include "User.h"
#include "Item.h"
#include "City.h"
#include <iostream>
#include <string>
#include <vector>


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
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$";
		citiesLi[i]->setInventroies(cities[i]->getInventories());

	}
	citiesLi = cities;
	randomCityAssigner();
	randomNextCityAssigner();

	for (int i = 0; i < currentCity->getInventories().size(); i++) {
		cout << "city name : " << currentCity->getCityName() << "\n";
		
	}
}

void User::randomCityAssigner() {
	srand(time(nullptr));
	int ran = rand() % 3;
	
	while (currentCity == NULL || citiesLi[ran] != currentCity) {

		currentCity = citiesLi[rand() % 3];
	}
	cout << "current city name: " << currentCity->getCityName() << "/n";

}
void User::randomNextCityAssigner() {
	//srand(time(nullptr));
	cout << " random value" << randomValue << "\n\n\n\n";
	srand(randomValue);
	if (randomValue == 1) randomValue = 0;
	else randomValue = 1;

	int ran = rand() % 3;

	do{

		nextCity = citiesLi[rand() % 3];
		//City* tempCity = citiesLi[rand() % 3];
		//if (nextCity != NULL) {
		//	while (tempCity == currentCity && tempCity == nextCity) {
		//		tempCity = citiesLi[rand() % 3];
		//	}
		//	nextCity = tempCity;
		//	
		//	/*if (tempCity == nextCity) {
		//	nextCity = currentCity;

		//	}
		//	else {
		//		nextCity = tempCity;
		//	}*/
		//}
		//else {
		//	nextCity = tempCity;
		//}
	} while (nextCity == currentCity || nextCity == tempCity);
	cout << "next city assigner function next city name: " << nextCity->getCityName() << "\n";
}

void User::inventoriesListDisplay() {
	cout << "################################################################################" << "\n";

	cout << "##### Item\t\t" << "Buying Price\t\t" << "Selling Price\t\t" <<"Quantity\n";
	for (int i = 0; i < inventories.size();i++) {
		cout << "##### " << i+1 << ". " << inventories.at(i)->getItemName() << "\t\t\t" << inventories[i]->getItemBuyingPrice()
			<< "\t\t\t" << inventories.at(i)->getItemSellingPrice() << "\t\t" << inventories.at(i)->getItemQuantity() << "\n";


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
	cout << "##### Item\t\t" << "Selling Price\n";
	for (int i = 0; i < inventories.size();i++) {
		cout << "##### " << i + 1 << ". " << inventories.at(i)->getItemName() << "\t\t\t" << inventories.at(i)->getItemSellingPrice() << "\n";
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
	cout << "going to user menu";
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
		cout << "##### Item \t\t" << " Price\n";
		for (int j = 0; j < citiesLi[i]->getInventories().size();j++) {
			cout << "##### " << j + 1 << ". " << citiesLi[i]->getInventories()[j]->getItemName() << "\t\t\t" << citiesLi[i]->getInventories()[j]->getItemSellingPrice() << "\n";

		}
		cout << "------------------------------------------------";
	}
	cout << "#############################################################" << "\n";
	cout << "Enter 0 to exit from buying menu : \n";
	//inventoriesListDisplay();
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
		
		//please uncomment this one %%%%%%%%
		for (int i = 0; i < inventories.size(); i++) {
			cout << "checking :: :: :: " << inventories[i]->getItemName() << " :: :: :: " << currentCity->getInventories()[ans - 1]->getItemName() << "\n";
			cout << "inventories[i]" << inventories[i]->getItemQuantity() << "\n";
			if (inventories[i]->getItemName() == currentCity->getInventories()[ans - 1]->getItemName()) {
				itemNumber = i;
				break;
			}
		}

		
		Item*  it = new Item();
		if (itemNumber == -1) {
			cout << currentCity->getInventories()[ans - 1]->getItemName() << "//////////////check here\n";
			it->setName(currentCity->getInventories()[ans -1 ]-> getItemName());
			cout << it->getItemName() << "//////////////////here 2\n";
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
			cout << "welcome to new city : " << currentCity->getCityName() << "\n";
			currentCity = nextCity;
			cout << "welcome to new city : " << currentCity->getCityName() << "\n";
			cout << "next city : " << nextCity->getCityName()<<"\n";
			randomNextCityAssigner();
			cout << "next city : " << nextCity->getCityName()<<"\n";
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
	
	cout << "Welcome to Smuggler Page : \n";
	cout << "Smuggler name : " << name << "\n";
	cout << "User's total money : " << userMoney << "\n";
	cout << "User's current City name : " << currentCity->getCityName() << "\n";
	
	
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
	//cout << "User's next city name : " << nextCity->getCityName() << "\n";
				
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
	cout << "now we are in fine checker \n *********** \n******\n*******";
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
		caughtPercentageCounter = 0;
		tempCity = currentCity;
		currentCity = nextCity;
		randomNextCityAssigner();
		
		//minimum one item require
		cout << "hello\n";
		if (!inventories.empty()) {
			inventories.pop_back();

		}
		/*else {
			gameLose = true;
			cout << "ohhh! You loss the game.\n";
		}*/
		userMoney -= fine;
		fine += 50;
		if (userMoney <= 0) {
			gameLose = true;
			cout << "ohh You lose the game!\n";
		
		}
		cout << "user MOney is : " << userMoney << "\n";

	}
}
	
