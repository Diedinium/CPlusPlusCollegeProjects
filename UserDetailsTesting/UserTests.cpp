#include "pch.h"
#include "CppUnitTest.h"
#include "../UserDetails/User.h"
#include "../UserDetails/User.cpp"
#include <ctime>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UserDetailsTesting
{
	User obj_user;
	double d_pay_per_hour;
	int i_hours_worked;
	double d_weeks_worked;
	double d_total_pay;

	TEST_CLASS(UserTests)
	{
	public:
		TEST_METHOD(AssignName)
		{
			std::string str_test_name = "Jake";
			obj_user.set_name(str_test_name);
			Assert::AreEqual(str_test_name, obj_user.get_name());
		}

		TEST_METHOD(AssignPayPerHour) {
			srand(time(NULL));
			d_pay_per_hour = rand() % 9 + 5;
			obj_user.set_pay_per_hour(d_pay_per_hour);
			Assert::AreEqual(d_pay_per_hour, obj_user.get_pay_per_hour());
		}

		TEST_METHOD(AssignHoursWorked) {
			srand(time(NULL));
			i_hours_worked = rand() % 150 + 3750;
			obj_user.set_hours_worked(i_hours_worked);
			Assert::AreEqual(i_hours_worked, obj_user.get_hours_worked());
		}

		TEST_METHOD(CalculateTotalPay) {
			srand(time(NULL));
			d_pay_per_hour = rand() % 9 + 5;
			i_hours_worked = rand() % 150 + 3750;
			d_total_pay = i_hours_worked * d_pay_per_hour;
			obj_user.set_pay_per_hour(d_pay_per_hour);
			obj_user.set_hours_worked(i_hours_worked);
			obj_user.calculate_total_pay();
			Assert::AreEqual(d_total_pay, obj_user.get_total_pay());
		}

		TEST_METHOD(CalculateWeeksWorked) {
			srand(time(NULL));
			i_hours_worked = rand() % 150 + 3750;
			d_weeks_worked = i_hours_worked / 37.5;
			obj_user.set_hours_worked(i_hours_worked);
			obj_user.calculate_weeks_worked();;
			Assert::AreEqual(d_weeks_worked, obj_user.get_weeks_worked());
		}
	};
}
