#pragma once
#include "Common.h"

class User
{
	std::string _str_name;
	int _i_hours_worked;
	double _d_pay_per_hour;
	double _d_total_pay;
	double _d_weeks_worked;
public:
	void set_name(std::string str_name) { _str_name = str_name; }
	std::string get_name() { return _str_name; }

	void set_hours_worked(int i_hours_worked) { _i_hours_worked = i_hours_worked; }
	int get_hours_worked() { return _i_hours_worked; }

	void set_pay_per_hour(double d_pay_per_hour) { _d_pay_per_hour = d_pay_per_hour; }
	double get_pay_per_hour() { return _d_pay_per_hour; }

	void calculate_total_pay();
	void calculate_weeks_worked();

	double get_total_pay() { return _d_total_pay; }
	double get_weeks_worked() { return _d_weeks_worked; }
};

