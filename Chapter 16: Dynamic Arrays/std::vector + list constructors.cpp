/*
Intro to std::vector
    std::vector is defined in the <vector> header and uses a template type parameter to define the data type contained in the array.

    Containers usually have a special constructor called a list constructor called when using an initializer list, which does 3 things:
        - Ensure the container has enough size to hold the provided initialization values (if applicable)
        - Set the length of the container to the number of elements in the initializer list (if applicable)
        - Initialize the elements following the sequential order of the initializer list

    We often want to initialize an array with a known length without populating it with values yet.
    std::vector has an explicit constructor that takes an std::size_t that specifies the length of the container.

    Constructor preferences:
        If the initializer list is empty, the default constructor is preferred over the list constructor.
        If the initializer list is non-empty, a matching list constructor is preferred over other matching constructors.

    When constructing a container (or any type that has a list constructor) with initializers that are not element values, use direct initialization.

    Behavior can change based on whether or not a list constructor exists for a container type. 
    It is safe to assume a container type will have one.

    std::vectors can be made const, and doing so means the container itself and its elements cannot be modified once initialized.
        Note that the element type cannot be const, as making the container const does so anyways.
    
    std::vector really should have been called an array

Accessing elements
    The most common way to access elements of an array is using operator[], the subscript operator.
        We provide an integral value known as a subscript or index to identify the element we want to select.
    Arrays in C++ are zero-based, meaning that index 0 is the first element in the array 
        Indexes are effectively a distance from the first element.

    operator[] does not do bounds checking. Passing a subscript that is not between 0 and N - 1 to an N-length array results in undefined behavior.
    Array elements are stored sequentially in memory, without gaps. This means they support random access, as any element contained can be accessed directly.
*/

#include <vector>
#include <iostream>

// direct member initialization is not allowed in class types for member default initializers.
// when providing a default initializer for a member:
    // we must use either copy initialization or list initialization (direct or copy).
    // CTAD is not allowed (so we must explicitly specify the element type).
struct Foo
{
    // This creates a std::vector with a capacity of 8, and then uses that as the initializer for v.
    std::vector<int> v{ std::vector<int>(8) }; // ok
    
};

int main()
{
	// Value initialization (uses default constructor)
	std::vector<int> empty{}; // vector containing 0 int elements, due to value initialization

    /// List construction (uses list constructor)
	std::vector<int> primes{ 2, 3, 5, 7 };          // vector containing 4 int elements with values 2, 3, 5, and 7
     // uses CTAD for deducing char type. (preferred)
	std::vector vowels { 'a', 'e', 'i', 'o', 'u' }; // vector containing 5 char elements with values 'a', 'e', 'i', 'o', and 'u'.  
    
    std::vector primes { 2, 3, 5, 7, 11 };
    std::cout << "The first prime number is: " << primes[0] << '\n';
    std::cout << "The second prime number is: " << primes[1] << '\n';
    std::cout << "The sum of the first 5 primes is: " << primes[0] + primes[1] + primes[2] + primes[3] + primes[4] << '\n';

    std::vector<int> data( 10 ); // vector containing 10 int elements, value-initialized to 0. uses the explicit constructor that takes std::size_t.
    // std::vector<int> data{ 10 }; // what about this?
    // {10} can be interpreted as either a size or as an initializer list. normally this would be ambiguous, but C++ specifically prefers matching list constructors.

    // Copy init
    //std::vector<int> v1 = 10;     // 10 not an initializer list, copy init won't match explicit constructor: compilation error

    // Direct init
    std::vector<int> v2(10);      // 10 not an initializer list, matches explicit single-argument constructor

    // List init
    std::vector<int> v3{ 10 };    // { 10 } interpreted as initializer list, matches list constructor

    // Copy list init
    std::vector<int> v4 = { 10 }; // { 10 } interpreted as initializer list, matches list constructor
    std::vector<int> v5({ 10 });  // { 10 } interpreted as initializer list, matches list constructor

            // Default init
            std::vector<int> v6 {};       // {} is empty initializer list, matches default constructor
            std::vector<int> v7 = {};     // {} is empty initializer list, matches default constructor


	return 0;
}