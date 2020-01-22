// ForLoopPowerOf10.cpp : Calculating to the power of 10

#include <iostream>

// Function that takes the starting value, and exponent
int power(int x, int y) {
	// Set starting power.
	int power = 1;
	// Return 1 if y is 0
	if (y == 0) {
		return 1;
	}
	// Loop until i is equal to the exponent (y)
	for (int i = 1; i <= y; i++) {
		// Multiply power by x
		power *= x;
	}
	return power;
}

int main()
{
	int x = 5;
	int y = 10;
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;

	std::cout << "x^y = " << power(x, y) << std::endl;

	return 0;
}


