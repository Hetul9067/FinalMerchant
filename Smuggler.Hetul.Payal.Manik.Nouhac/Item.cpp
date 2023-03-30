
#include "Item.h"
#include <iostream>
#include <string>
#include <Random>
#include <iomanip>

//#ifndef ITEM_CPP;
////#endif ITEM_CPP;
//#define Item_CPP
// 

using namespace std;
Item::Item() {

}
Item :: Item(string name, float bPrice, float quantity) {
	cout << fixed << setprecision(2);
	itemName = name;
	//cout << "hello item we are in " << itemName << "@@@@@@@@@@@@@@@@@\n";
	//itemBuyingPrice = bPrice;
	randomlySetBuyingPrice(bPrice);
	randomlySetSellingPrice();
	itemQuantity = quantity;

}


//randomly setting the buying price
void Item::randomlySetBuyingPrice(float bPrice) {
	//srand(time(nullptr));

	float maxPrice = bPrice * 1.50;
	//cout << "bprice : " << bPrice << "\n";
	//cout << "maxPrice : " << maxPrice << "\n";
	
	int randomInt = rand();

	float randomFloat = static_cast<float>(randomInt) / RAND_MAX;
	
	itemBuyingPrice = (maxPrice - bPrice) * randomFloat + bPrice;

	//cout << "item buying Price : " << itemBuyingPrice <<"\n";

}

//randomly setting the selling price
void Item::randomlySetSellingPrice() {
	//srand(time(nullptr));

	float maxPrice = itemBuyingPrice * 1.50;
	//cout << "item buying Price : " << itemBuyingPrice << "\n";
	
	//cout << "maxPrice : " << maxPrice << "\n";
	
	int randomInt = rand();

	float randomFloat = static_cast<float>(randomInt) / RAND_MAX;

	itemSellingPrice = (maxPrice - itemBuyingPrice ) * randomFloat + (itemBuyingPrice + 1);
	//itemSellingPrice = (rand() % (maxPrice - (int)itemBuyingPrice + 3)) + itemBuyingPrice;
	//cout << "item selling Price : " << itemSellingPrice << "\n";

}


string Item::getItemName() {
	return itemName;
}
void Item:: setName(string name) {
	itemName = name;
}

float Item:: getItemBuyingPrice() {
	return itemBuyingPrice;
}
void Item:: setItemBuyingPrice(float price) {
	itemBuyingPrice = price;
}

float Item:: getItemSellingPrice() {
	return itemSellingPrice;
}
void Item:: setItemSellingPrice(float price) {
	itemSellingPrice = price;
}
float Item::getItemQuantity() {
	return itemQuantity;
}

void Item::setItemQuantity(float quantity) {
	itemQuantity = quantity;
	
}


