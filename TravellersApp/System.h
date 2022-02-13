#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Tour.h"
#include "FriendsList.h"
#include "DestinationList.h"

//! A class that runs the program
class System
{
public:
	static System& i();

    //! Creates a new user and saves it's information to "Users.bin"
	User signUp(int& count, ofstream& out);
	//! By entered username and password, returns the index of the user i want to login
	int signIn(const int count);
	//! A function that checks if the selected username is valid. (contains only letters and numbers)
	bool NameValidation(const string name);
	//! A function that checks if a photo is in the right format
	bool PhotoValidation(const string photo);
	//! Adds a friend to the user's friend list
	bool addFriend(User& cur_user, const int count);
	//! Adds a tour to the user's personal account
	void Addtour(User& cur_user, int& destNumber);
	//! Prints all user's friends and the destinations that they have visited
	void FriendsAndDestinations(const User& cur_user, const int destNumber);
	//! Runs the program
	int run();

private:
	System();
	User* users; //!< Pointer to User, keeps all users in array
	DestinationsList* destlist; //!< Pointer to DestinationsList, keeps all destinations in array
};

