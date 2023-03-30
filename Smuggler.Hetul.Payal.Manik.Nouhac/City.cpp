#include "City.h"
#include "Item.h"
#include<iostream>
#include<string>
#include<list>
#include<sstream>
#include<vector>
#include<cstdlib>


using namespace std;

City::City() {

}

City ::City(string name) {
	cityName = name;
	itemsReferenceLi.push_back("Lsd");
	itemsReferenceLi.push_back("Weed");
	itemsReferenceLi.push_back("Heroin");
	itemsReferenceLi.push_back("Cocaine");
	itemsReferenceLi.push_back("Cetamine");
	
}


bool City::checkInt(float x) {
	{
		while (cin.fail() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(512, '\n');
			return true;
		}
		return false;
	}
}

bool City::checkFloat(float x) {
	while (cin.fail() || cin.peek() != '\n') {
		cin.clear();
		cin.ignore(512, '\n');
		return true;
	}
	return false;

	/*if (isalpha(x))	return false;
	if (isnan(x)) {
		return false;
	}
	if (isinf(x)) return false;
	if (floor(x) == x) return false;
	if (!isdigit(x) && x != '.' && x != '-')	return false;
	return true;*/
}


//for selling wares
void City::sellsItem() {
	int ans = 0;
	float quantity = 0;
	bool quantityChecker = false;
	

	
	cout << "#############################################################" << "\n";
	cout << "##### Item\t\t" << "Selling Price\t\t" << "Quantity\n";
	for (int i = 0; i < inventories.size();i++) {
		cout << "##### " << i + 1 << ". " << inventories.at(i)->getItemName() << "\t\t\t" << inventories.at(i)->getItemSellingPrice() << "\t\t\t" << inventories.at(i)->getItemQuantity() << "\n";
	}
	
	bool checker1 = true;
	do {
		try {
			checker1 = false;
			cout << "#############################################################" << "\n";

	
			cout << "Please enter the item number for selling : \n";
			cin >> ans;


			if (checkInt(ans)) throw 10;
			if (ans < 0 || ans > inventories.size()) throw 20;
		}
		catch (...) {

			checker1 = true;
			cout << "#########################\n";
			cout << "Please enter valid input!\n";
			cout << "#########################\n";
		}
	} while (checker1);

	

	do {


		bool checker = true;
		do {
			try {
				checker = false;
				cout << "Please enter the quantities of the " << inventories[ans - 1]->getItemName() << " : \n";
				cin >> quantity;

				if (checkFloat(quantity)) throw 10;
				//if (ans < 1 || ans > 4) throw 20;
			}
			catch (...) {

				checker = true;
				cout << "#########################\n";
				cout << "Please enter valid Quantities!\n";
				cout << "#########################\n";
			}
		} while (checker);



		quantityChecker = false;
		if (quantity > inventories[ans - 1]->getItemQuantity()) {
			cout << "########################################\n";
			cout << "Sorry, we don't have that much quantity \n";
			quantityChecker = true;

		}
	} while (quantityChecker);

	
	cout << "################################";
	cout << "####       Item sold        ####\n";
	cout << "################################";


	
	//decreasing city's item quantity after selling it successfully 
	inventories[ans - 1]->setItemQuantity(inventories[ans - 1]->getItemQuantity() - quantity);
	cout << "going to city menu";
	cityMenu();
}

void City::buyTheirWares() {
	int ans = 0;
	float quantity = 0;
	bool quantityChecker = false;
	

	cout << "#############################################################\n";
	cout << "------------------------------------------------\n";
	for (int i = 0; i < itemsReferenceLi.size();i++) {
		cout << "##### " << i + 1 << ". " << itemsReferenceLi.at(i) << ".\n";
	}
	
	cout << "------------------------------------------------\n";
	cout << "#############################################################" << "\n";

	
	
	bool checker1 = true;
	do {
		try {
			checker1 = false;
			cout << "#############################################################" << "\n";
			cout << "Enter 0 to exit from buying menu : \n";
	
			cout << "Please enter the item number to buy item for " << cityName << " : \n";
			cin >> ans;

			if (checkInt(ans)) throw 10;
			if (ans < 0 || ans > itemsReferenceLi.size()) throw 20;
		}
		catch (...) {

			checker1 = true;
			cout << "#########################\n";
			cout << "Please enter valid input!\n";
			cout << "#########################\n";
		}
	} while (checker1);

	
	if (ans == 0) {
		cout << "Thank you for visiting buying menu!";
		return;
	}

	bool checker = true;
	do {
		try {
			checker = false;
			cout << "Please enter the quantities of the " << itemsReferenceLi[ans - 1] << " : \n";
			cin >> quantity;
	
	
			if (checkFloat(quantity)) throw 10;
			//if (ans < 1 || ans > 4) throw 20;
		}
		catch (...) {

			checker = true;
			cout << "#########################\n";
			cout << "Please enter valid Quantities!\n";
			cout << "#########################\n";
		}
	} while (checker);



	cout << "#################################\n";
	cout << "Item has been bought successfully!\n";
	cout << "#################################";

	//increasing city's item quantity after buying it successfully
	int itemNumber = -1;
	for (int i = 0; i < inventories.size(); i++) {
		if (inventories[i]->getItemName() == itemsReferenceLi[ans - 1]) {
			itemNumber = i;
			break;
		}
	}
	if (itemNumber == -1) {
		srand(time(nullptr));
		int ran = rand() % (50-10 +1)+10;
		float bPrice = ran;
			
		Item* it = new Item(itemsReferenceLi.at(ans - 1), bPrice, 0);
		inventories.push_back(it);
		itemNumber = inventories.size()-1;

	}

	inventories[itemNumber]->setItemQuantity(inventories[itemNumber]->getItemQuantity() + quantity);
	cout << "it's finished\n";

	cityMenu();
}

void City::cityAnsChecker(int a) {
	switch (a) {
	case 1:
		sellsItem();
		break;
	case 2:
		buyTheirWares();
		break;
	
	}
}


void City::cityMenu() {
	system("cls");
	cout << "###############################################################" << "\n";
	cout << "welcome to " << cityName << "\n";
	cout << "#####| Item\t\t|" << "Buying Price|\t\t|" << "Selling Price|\t\t|"<<"Quantity|\n";
	for (int i = 0; i < inventories.size();i++) {
		cout << "#####| " << inventories.at(i)->getItemName() << "\t\t\t|" << inventories.at(i)->getItemBuyingPrice()
			<< "|\t\t\t|" << inventories.at(i)->getItemSellingPrice() << "\t\t\t|" << inventories.at(i)->getItemQuantity() << "|\n";


	}
	cout << "###############################################################" << "\n";

	int ans = 0;
	cout << "1. Sell city's wares\n";
	cout << "2. Buy city's wares\n";
	cout << "3. Going back to Main Page\n";
	
	
	
	bool checker = true;
	do {
		try {
			checker = false;
			cout << "Please enter the require option : \n";
			cin >> ans;
			if (checkInt(ans)) throw 10;
			if (ans < 1 || ans > 3) throw 20;
		}
		catch (...) {

			checker = true;
			cout << "#########################\n";
			cout << "Please enter valid input!\n";
			cout << "#########################\n";
		}
	} while (checker);

	
	if (ans == 3) return;
	cityAnsChecker(ans);
	
	

}


string City::getCityName() {
	return cityName;
}

void City::setCityName(string name) {
	cityName = name;
}


vector<Item*> City::getInventories() {
	return inventories;
}

void City::setInventroies(vector<Item*> inv) {
	
	inventories = inv;
}


