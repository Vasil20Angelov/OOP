#pragma once
#include <iostream>
//! Struct
struct Date
{
	int year;
	int month;
	int day;

    //! Checks if the entered date is correct
	bool DateValidation();
	//! Checks if 2 dates are equal
	bool Same_date(Date d2);
	//! Checks if a date is between other 2 dates
	bool InPeriod(Date d1, Date d2);
	//! Checks if a product is with expired date by comparing to another date
	bool ExpiredDate(Date e1);
	//! Compares 2 dates
	bool DateCompare(Date d2);
	//! Enters a date
	void Set_Date();
	//! Prints a date
	void Show_Date() const;
};
