



#ifndef  _ITEM_H_
#define _ITEM_H_

#include <iostream>
#include <string>
using namespace std;

class Item {
	private:
		string itemName;
		float itemBuyingPrice;
		float itemSellingPrice;
		float itemQuantity;

	public:
		Item();
		Item(string name, float bPrice, float quantity);

		void randomlySetBuyingPrice(float bPrice);

		string getItemName();

		void setName(string name);

		float getItemBuyingPrice();

		void setItemBuyingPrice(float price);

		void randomlySetSellingPrice();

		float getItemSellingPrice();

		void setItemSellingPrice(float price);

		float getItemQuantity();

		void setItemQuantity(float quantity);


};
#endif // ! _ITEM_H_