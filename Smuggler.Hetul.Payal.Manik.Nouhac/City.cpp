#include "City.h"
#include "Item.h"
#include<iostream>
#include<string>
#include<list>
#include<sstream>
#include<vector>



using namespace std;

City::City() {

}

City ::City(string name) {
	cityName = name;
	itemsReferenceLi.push_back("LSD");
	itemsReferenceLi.push_back("Weed");
	itemsReferenceLi.push_back("Heroin");
	itemsReferenceLi.push_back("Cocaine");
	itemsReferenceLi.push_back("Cetamine");
	
}
//for selling wares
void City::sellsItem() {
	int ans = 0;
	int quantity = 0;
	bool quantityChecker = false;
	//float earnedMoney = 0;


	cout << "#############################################################" << "\n";
	cout << "##### Item\t\t" << "Selling Price\t\t" << "Quantity\n";
	for (int i = 0; i < inventories.size();i++) {
		cout << "##### " << i + 1 << ". " << inventories.at(i)->getItemName() << "\t\t\t" << inventories.at(i)->getItemSellingPrice() << "\t\t\t" << inventories.at(i)->getItemQuantity() << "\n";
	}
	cout << "#############################################################" << "\n";

	//inventoriesListDisplay();
	cout << "Please enter the item number for selling : \n";
	cin >> ans;

	do {

		cout << "Please enter the quantities of the " << inventories[ans - 1]->getItemName() << " : \n";
		cin >> quantity;
		quantityChecker = false;
		if (quantity > inventories[ans - 1]->getItemQuantity()) {
			cout << "########################################\n";
			cout << "Sorry, we don't have that much quantity \n";
			quantityChecker = true;

		}
	} while (quantityChecker);

	//earnedMoney = quantity * inventories[ans - 1].getItemSellingPrice();
	/*cout << "################################";
	cout << "Earned amount : " << earnedMoney << "\n";
	cout << "################################";*/

	cout << "################################";
	cout << "####       Item sold        ####\n";
	cout << "################################";


	//increasing user's money after selling the item
	//userMoney += earnedMoney;

	//decreasing user's item quantity after selling it successfully 
	inventories[ans - 1]->setItemQuantity(inventories[ans - 1]->getItemQuantity() - quantity);
	cout << "going to city menu";
	cityMenu();
}

void City::buyTheirWares() {
	int ans = 0;
	float quantity = 0;
	bool quantityChecker = false;
	//float investedMoney = 0;


	cout << "#############################################################\n";
	cout << "------------------------------------------------\n";
	for (int i = 0; i < itemsReferenceLi.size();i++) {
		cout << "##### " << i + 1 << ". " << itemsReferenceLi.at(i) << ".\n";
	}
	/*cout << "##### 2. Weed\n";
	cout << "##### 3. Heroin\n";
	cout << "##### 4. Cocaine\n";
	cout << "##### 5. Cetamine\n";
	*/
	cout << "------------------------------------------------\n";
	cout << "#############################################################" << "\n";

	//for (int i = 0; i < .size();i++) {
	//	cout << "city name : " << citiesLi[i]->getCityName() << "\n";
	//	cout << "##### Item \t\t" << "selling Price\n";
	//	for (int j = 0; j < citiesLi[i]->getInventories().size();j++) {

	//	}
	//}
	cout << "Enter 0 to exit from buying menu : \n";
	//inventoriesListDisplay();
	cout << "Please enter the item number to buy item for " << cityName << " : \n";
	cin >> ans;
	if (ans == 0) {
		cout << "Thank you for visiting buying menu!";
		return;
	}

	cout << "Please enter the quantities of the " << itemsReferenceLi[ans - 1] << " : \n";
	cin >> quantity;
	//quantityChecker = false;
	



		cout << "#################################\n";
		cout << "Item has been bought successfully!\n";
		cout << "#################################";

		//increasing user's item quantity after buying it successfully
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
	cout << "Please enter the require option : \n";
	cin >> ans;
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
	/*for (int i = 0; i < inventories.size();i++) {
		cout << "#####| " << inventories.at(i).getItemName() << "\t\t\t|" << inventories.at(i).getItemBuyingPrice()
			<< "|\t\t\t|" << inventories.at(i).getItemSellingPrice() << "|\n";


	}
	cout << "hello inventroies$$$";*/
}


