/*
Enumerations
    An enumeration, or enumerated type or enum, is a compound data type whose values are restricted to a set of named symbolic constants called enumerators
        They are defined using the enum keyword.

    Enumerations do not have to be named, but they should be. Enumerators must be named.
    Commonly defined enumerations include days of the week, the cardinal directions, and the suits in a deck of cards

    Since these enums are unscoped, the enumerators share their scope with the enumeration. 
    Both are in the global scope, meaning that enumerator names cannot overlap within the same scope, even within different enumerations.
    
    Enumerators can be accessed both through the global scope as well as through the enumeration using the scope resolution operator.
    Prefer putting enumerations inside a named scope region (such as a namespace or class) so the enumerators don’t pollute the global namespace.

    Each enumerator is automatically associated with an integer value based on its position in the enumerator list.
    By default, the first enumerator has integer 0, and each subsequent one is 1 more than the previous.
    They can be assigned values, and even overlapping ones (even though non-distinct enums should be avoided).

    Since 0 is the default when initializing, it is best for the '0' enum to be the most default or expected case.
    However, an unscoped enumeration will implicitly convert to an integral value. Because enumerators are compile-time constants, this is a constexpr conversion
    Most compilers use int as an underlying type for enumerations.

*/

// Define a new unscoped enumeration named Color
enum Color
{
    // Here are the enumerators
    // These symbolic constants define all the possible values this type can hold
    // Each enumerator is separated by a comma, not a semicolon
    black,   // 0
    red,     // 1
    blue,    // 2
    green,   // 3
    white,   // 4
    cyan,    // 5
    yellow,  // 6
    magenta, // 7,
    // trailing comma optional but recommended
}; // the enum definition must end with a semicolon

enum Animal
{
    cat = -3,    // values can be negative
    dog,         // -2
    pig,         // -1
    horse = 5,
    giraffe = 5, // shares same value as horse
    chicken,     // 6
};


enum Feeling
{
    happy,
    tired,
    //blue, // error: naming collision with the above blue
};


// some common enums
enum DaysOfWeek
{
    sunday,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
};

enum CardinalDirections
{
    north,
    east,
    south,
    west,
};

enum CardSuits
{
    clubs,
    diamonds,
    hearts,
    spades,
};

enum FileReadResult
{
    readResultSuccess,
    readResultErrorFileOpen,
    readResultErrorFileRead,
    readResultErrorFileParse,
};

int openFile();
int readFile();
int parseFile();

FileReadResult readFileContents()
{
    if (!openFile())
        return readResultErrorFileOpen;
    if (!readFile())
        return readResultErrorFileRead;
    if (!parseFile())
        return readResultErrorFileParse;

    return readResultSuccess;
}

int main()
{
    // Define a few variables of enumerated type Color
    Color apple { red };   // my apple is red
    Color shirt { green }; // my shirt is green
    Color cup { blue };    // my cup is blue

    // Color socks { white }; // error: white is not an enumerator of Color
    // Color hat { 2 };       // error: 2 is not an enumerator of Color

    return 0;
}