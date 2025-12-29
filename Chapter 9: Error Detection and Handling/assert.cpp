/*
assert
    Assertions are expressions that are true unless there is a bug in the program. 
        If its conditional portion evaluates to false, it displays an error message and terminates the program via std::abort().
    They are also used for portions of code that are not implemented yet.

    The assert preprocessor macro lives in the <cassert> header, used for runtime assertions.
        To make the error messages descriptive, we can add && followed by the error message to the condition.

    Since there is some amount of performance spent with the error checking, assert statements are designed to be disabled via the NDEBUG macro.
    If it is defined, the asserts will be disabled automatically.  
*/

/*
static_assert
    static_assert is checked at compile-time rather than runtime. It is a keyword, and thus needs no header.
    Since it is not checked at runtime, it must check a constant expression. It takes the form static_assert(condition, diagnostic_message).
    
    They can be placed anywhere, including the global namespace. They are not deactivated in release builds, and have no runtime cost.
*/
#define NDEBUG // must be above includes. comment this out to allow asserts
#include <cassert> // for assert()
#include <cmath> // for std::sqrt
#include <iostream>

static_assert(sizeof(long) == 8, "long must be 8 bytes");
static_assert(sizeof(int) >= 4, "int must be at least 4 bytes");

double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
{
  assert(gravity > 0.0 && "Gravity is negative!\n"); // The object won't reach the ground unless there is positive gravity.

  if (initialHeight <= 0.0)
  {
    // The object is already on the ground. Or buried.
    return 0.0;
  }

  return std::sqrt((2.0 * initialHeight) / gravity);
}

int main()
{
  std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";

  return 0;
}