#include "User.h"

void User::calculate_total_pay() 
{
	_d_total_pay = _d_pay_per_hour * _i_hours_worked;
}

void User::calculate_weeks_worked() 
{
	_d_weeks_worked = _i_hours_worked / 37.5;
}