/*
Mersenne Twister
    The <random> header enables all the randomization capabilities in C++

    mt19937 is a Mersenne Twister that generates 32-bit unsigned integers
    mt19937_64 is a Mersenne Twister that generates 64-bit unsigned integers

    Let's say we wanted to simulate a dice roll. We can't simply use a random 32-bit integer, but we can use a random number distribution to effectively shorten the range
    In this case, we want equal chance of all 6 values, meaning we can use a uniform distribution.

    So long as the seed is random, we can generate different values each time the program is ran.
    One straightforward strategy is to use the value of the system clock. The current time will be different for each time the program is ran, providing a seed to base other values on.
        A downside is that if the program is ran multiple times in close succession, the random values will not differ very much between each iteration since the current time is a similar value.
    
    The random library contains a type called std::random_device that is an implementation-defined PRNG. It is not required to be non-deterministic
    It is good practice to use this however when seeding, and only seed once.
*/

#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution

int main()
{
	std::mt19937 mt{};

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt) << '\t'; // generate a roll of the die here. note that mt, not mt() is passed in here.

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

    // Seed our Mersenne Twister using steady_clock
	std::mt19937 mt{ static_cast<std::mt19937::result_type>(
		std::chrono::steady_clock::now().time_since_epoch().count()
		) };

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

    	std::mt19937 mt{ std::random_device{}() };

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution die6{ 1, 6 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 40; ++count)
	{
		std::cout << die6(mt) << '\t'; // generate a roll of the die here

		// If we've printed 10 numbers, start a new row
		if (count % 10 == 0)
			std::cout << '\n';
	}

	return 0;
}