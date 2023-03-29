
#ifndef _CITY_H_
#define _CITY_H_

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
using namespace std;

class City {
private:
	string cityName;
	float buyingPrice;
	float sellingPrice;
	vector<string> itemsReferenceLi;

	vector<Item*> inventories;

public:
	
	City();
	City(string name);

	void cityAnsChecker(int a);

	void cityMenu();

	void sellsItem();

	void buyTheirWares();

	string getCityName();

	void setCityName(string name);

	float getBuyingPrice();

	void setBuyingPrice(float price);

	vector<Item*> getInventories();

	void setInventroies(vector<Item*> inv);



};
#endif // !_CITY_H_