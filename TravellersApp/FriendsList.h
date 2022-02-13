#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//! The class adds and keeps information about the user's friend's list
class FriendsList
{
public:

    //! Default constructor
	FriendsList();
	//! Creates an object with exact memory for a dynamic allocated array (string*)
	FriendsList(int friendsNum);
	//! Destructor
	~FriendsList();

    //! Checks if a user is already added so it won't add it again
	bool AlreadyAdded(const string new_friend);
	//! Adds a user to the friend's list
	void addFriend(const string new_friend);
	//! Gets information for the friend's list from the user's personal binary file
	void ReadData(ifstream& in);
	//! Saves the information for the user's friend's list to his personal binary file
	void SaveData(ofstream& out) const;
	//! Returns the name of user's friend
	const string ShowFriends(int index) const;
	//! Returns the count of user's friends
	const int getFriendsNum() const;

private:

	string* friends; //!< An array that keeps all users' names that are in the friend's list
	int friendsNum; //!< Keeps the number of user's friends
};

