#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Tour.h"
using namespace std;

//! A class that creates and holds information about the destinations in the agency
class DestinationsList
{
public:

    //! Default constructor
	DestinationsList();
	//! Creates a destination
	DestinationsList(const string& destination, const string& user, const string& comment, short grade);
	//! Copy constructor
	DestinationsList(const DestinationsList& other);
	//! Redefined operator "=" for the class
	DestinationsList& operator=(const DestinationsList& other);
	//! Destructor
	~DestinationsList();

    //! Gets the information about the destinations from a binary file
	void LoadData(ifstream& in);
	//! Saves all destinations in a binary file
	void SaveData(ofstream& out) const;
    //! Adds a user's comment and grade for an existing destination
	void addReview(const string user, const string comment, short grade);
	//! Prints all reviews for a destination
	void ShowReviews() const;
	//! Prints all destinations the selected user has visited and their grade for it
	void User_Tour(const string user) const;
	//! Returns the name of a destination
	const string getDestination() const;

    //! Prints a destination and it's average grade
	friend ostream& operator<<(ostream& out, const DestinationsList& obj);

private:
    //! Copy
	void copy(const DestinationsList& other);
	//! Clears dynamic memory
	void clear();

	string destination; //!< The name of the destination
	string* user; //!< An array that keeps the names of all users that have visited a certain destination
	string* comment; //!< An array that keeps all comments for a certain destination
	short* grade; //!< An array that keeps all grades for a certain destination
	int reviews; //!< The number of reviews for a certain destination
	double avr_grade; //!< The average grade for a certain destination

};
