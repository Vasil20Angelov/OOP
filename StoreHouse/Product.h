#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Location.h"
using namespace std;

//! The class creates a product with all parameters needed for the project
class Product
{
public:

    //! Default constructor
	Product();
	//! Creates a product with starting location and calls setEndLocation(...) to calculate and set the ending location
	Product(const string& product_name, const string& unit, const string& producer, const string& comment, int amount, Date expiry, Date placed_date, Location loc_start);

	//! Loads the information about a product from a binary file
	void load_info(ifstream& in);
	//! Saves the information about a product in a binary file
	void save_info(ofstream& out) const;
	//! Sets a new amount for a product. (Used when removing a certain amount from a product)
	void newAmount(int amount);
	//! Sets a new ending location for a product. (Used after setting a new amount in order to clear the unused space in the storehouse)
	void newELocation(int amount);

    //! Checks if location is available to place a product there
	bool checkLocation(Location l1, Location l2);
	//! Compares a placed product's name and expiry date with unplaced. If true, the unplaced can be put to the placed one
	bool checkName_Date(const string& name, const Date expiryD);
	//! Checks if a product is already expired
	bool expired_date(const Date e1);
	//! Compares the expiry dates of 2 products
	bool compareEdate(const Date d2);

    //! Returns product's name
	const string get_productname() const;
	//! Returns product's unit (kg/l)
	const string get_unit() const;
	//! Returns product's producer
	const string get_producer() const;
	//! Returns product's comment
	const string get_comment() const;
	//! Returns product's amount
	const int get_amount() const;
	//! Returns product's expiry date
	const Date get_expiryDate() const;
	//! Returns product's placed date (when the product was placed in the storehouse)
	const Date get_placedDate() const;
	//! Returns product's starting location
	const Location get_Slocation() const;
	//! Returns product's ending location
	const Location get_Elocation() const;

private:

	string product_name; //!< Product's name
	string producer; //!< Product's producer
	string unit; //!< Product's unit
	string comment; //!< Product's  comment
	int amount; //!< Product's amount
	Date expiry; //!< Product's expiry date
	Date placed_date; //!< Product's placed date (when the product was placed in the storehouse)
	Location loc_start; //!< Product's starting location
	Location loc_end; //!< Product's ending location
};

