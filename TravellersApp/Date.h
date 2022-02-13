#pragma once
//! Struct
struct Date
{
public:

	short day;
	short month;
	short year;

	//! Checks if the entered date is valid
	bool DateValidation();
	//! Checks if the departure day is after the arrival date
	bool DataComparison(const Date& other);
	//! The user enters a date
	void EnterDate();
	//! Prints a date
	void ShowDate() const;
};
