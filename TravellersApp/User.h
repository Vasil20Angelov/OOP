#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Date.h"
#include "Tour.h"
#include "FriendsList.h"
using namespace std;

//! Creates a user and keeps his personal information
class User
{
public:
	static int ToursCount; //!< Keeps the number of tours the user has added to his account
	static int FriendsCount; //!< Keeps the number of friends the user has

    //! Default constructor
	User(const string& nickname = "", const  string& password = "", const string& email = "");
	//! Copy constructor
	User(const User& other);
	//! Redefined operator "=" for the class
	User& operator=(const User& other);
	//! Destructor
	~User();

    //! Reads from a binary file the name, password and email of all users
	void Users_Data(ifstream& in);
	//! Saves the name, password and email of all users
	void Save_newUsers(ofstream& out) const;
	//! Loads the whole information for the selected user from his personal file
	void LoadAccInfo(ifstream& in);
	//! Saves the whole information of the selected user to his personal file
	void SaveAccInfo(ofstream& out);

    //! Adds a new tour to user's account
	void addnewtour(const string destination, Date aDate, Date dDate, short grade, const string comment, int photos_num);
	//! Adds photos for a certain tour
	void addPhotos(int index, const string photo);
	//! Adds new friends to user's friend's list
	void addNewFriends(const string friends_name);
	//! Prints all destinations the selected user has visited and his review about it
	void ShowPersonalData() const;
	//! Checks if a user is already added to the user's friend's list
	bool CheckifAdded(const string friends_name);

    //! Returns user's nickname
	const string getNickname() const;
	//! Returns user's password
	const string getPassword() const;
	//! Returns user's email
	const string getEmail() const;
	//! Returns user's friends' count
	const int getFriendsCount() const;
	//! Returns a user's friend
	const string ShowFriendsList(int index) const;

private:
    //! Copy
	void copy(const User& other);
	//! Clears dynamic memory
	void clear();

	string nickname; //!< The name of the user
	string password; //!< The password of the user
	string email; //!< The email of the user
	FriendsList friends; //!< Keeps the friends of the user
	Tour* tours; //!< Pointer to Tour, keeps all tours that the user has made

};


