#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Product.h"
using namespace std;

//! The class stores all products in the storehouse
class Storehouse
{
public:

	static int CurIndex;
	static int CurIndex2;

    //! Default constructor
	Storehouse();
	//! Loads the storehouse with all products from a binary file
	Storehouse(ifstream& in);

    //! Saves all products in the storehouse to binary file
	void SaveData(ofstream& out) const;
	//! Prints on the screen all products from the storehouse
	void ProductsList() const;
	//! Resets CurIndex & CurIndex2 to 0
	void resetCurIndex();
	//! Sets a new amount for a product
	void SetNewAmount(int index, int amount);
	//! Sets a new ending location for a product
	void SetNewELocation(int index, int amount);
	//! Adds a new product to the storehouse
	void AddProduct(const Product& obj);
	//! Removes a product from the storehouse
	void RemoveProduct(int index);
	//! Returns the index of the product i want to remove
	int RemoveProducts(const string& name);
	//! Removes all expired products from the storehouse
	int ClearStorehouse(const Date expiryD);
	//! Checks if a location is available to place a product there
	bool AvailableLocation(const Location l1, const Location l2);
	//! Checks if a product has the same name and expiry date with another product. If yes, returns it's index
	int Name_date_Match(const string& name, const Date expiryD);

    //! Returns the number of the products in the storehouse
	const int getCount() const;
	//! Returns product's amount
	const int getAmount(int index) const;
	//! Returns product's name
	const string getName(int index) const;
	//! Returns product's unit (kg/l)
	const string getUnit(int index) const;
	//! Returns product's expiry date
	const Date getEdate(int index) const;
	//! Returns product's starting location
	const Location getSLoc(int index) const;
	//! Returns product's ending location
	const Location getELoc(int index) const;

private:

	vector <Product> products; //!< A vector that contains all products
	int productsCount; //!< The count of the products in the storehouse
};

