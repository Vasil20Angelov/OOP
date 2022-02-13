#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
using namespace std;

//! The class keeps information for any destination the user has visited
class Tour
{
public:
    //! Default constructor
	Tour();
	//! Creates an object with dynamically allocated memory for the photos
	Tour(const string& destination, Date aDate, Date dDate, short grade, const string& comment, int photos_num);
	//! Copy constructor
	Tour(const Tour& other);
	//! Redefined operator "=" for the class
	Tour& operator=(const Tour& other);
	//! Destructor
	~Tour();

    //! Reads information about the user's tours from a binary file
	void LoadData(ifstream& in);
	//! Saves all user's tours in a binary file
	void SavaData(ofstream& out) const;
	//! Adds photos to user's tour
	void AddPhotos(int index, const string photos);
	//! Shows all destinations that the user's has visited
	void ShowTour() const;
	//! Returns the name of a destination
	const string getdest() const;

private:
    //! Copy
	void copy(const Tour& other);
	//! Clears memory
	void clear();

	string destination; //!< Name of destination that the user has visited
	Date aDate; //!< The date when the user has started his tour
	Date dDate; //!< The date when the user has ended his tour
	short grade; //!< The grade given by the user for a destination
	int photos_num; //!< The number of photos, the user wants to upload

	string comment; //!< A comment for the destination
	string* photos; //!< The photo's names

};
