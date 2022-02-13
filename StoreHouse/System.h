#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Storehouse.h"
#include "Product.h"
#include "Location.h"
#include "Date.h"
using namespace std;

//! The class executes the program
class System
{
public:
	static string Lfile; //!< Sets a default name for the file that contains information about all products and the date when they have been ever added
	static System& i(); //!< Singleton design pattern

    //! Prints a menu. Different options are shown when a file is opened/closed
	void ShowMenu(bool file_opened) const;
	//! Shows a help menu
	void ShowHelp(bool file_opened) const;
	//! Opens a file and loads it's information
	bool OpenFile();
	//! Saves the products to a file
	bool Savetofile();
	//! Adds a product to the log file (the file that contains information about all products and their placed date)
	bool AddtoLogfile(Date logDate, string product_name, int amount, const char sign);
	//! Removes a product from the storehouse
	bool RemoveProduct();
	//! Removes the expired products and calculates losses
	bool Clear();
	//! Loads and shows the information from the log file
	bool ReadFromLogfile();
	//! Adds a product to the storehouse
	void AddProduct();

    //! Runs the program
	int run();
private:

	System();
	Storehouse storehouse; //!< The storehouse the user is working with. Contains products and supports all options from the project
	string file_location; //!< The file's name the user is work with. The storehouse loads/saves the products from/to this file
};

