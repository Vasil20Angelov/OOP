#pragma once
//! Struct
struct Location
{
	int section; //!< 1 section contains 10 shelfs
	int shelf; //!< 1 shelf has 10 numbers
	int number; //!< in 1 number can be stored 10 kg/l of any product

    //! Sets a starting location next to other product
	void setStartLocation(const Location& l1);
    //! Sets a random location in the storehouse
	void setRandomLocation();
	//! Sets the ending location according to the starting position and the amount
	void setEndLocation(const Location& l1, int amount);
	//! Prints the location
	void showLocation() const;

};
