/*
Numeric Conversions
    There are 5 basic types of numeric conversions
        - Converting an integral type to any other integral type
        - Converting a floating point type to any other floating point type
        - Converting a floating point type to any integral type
        - Converting an integral type to any floating point type
        - Converting an integral type or a floating point type to a bool
    
    Unlike numeric promotions, some numeric conversions are unsafe, meaning that at least one value of the source type cannot be converted into an equal value of the destination type.
        Value-preserving conversions are safe numeric conversions where the destination type can exactly represent all possible values in the source type.
        Reinterpretive conversions are unsafe numeric conversions where the converted value may be different than the source value, but no data is lost. Signed/unsigned conversions fall into this category.  
        Lossy conversions are unsafe numeric conversions where data may be lost during the conversion.
    
    The compiler will generally warn if a conversion leads to a potential loss of information.
*/

int main() {

    short s = 3; // convert int to short
    long l = 3; // convert int to long
    char ch = s; // convert short to char
    unsigned int u = 3; // convert int to unsigned int

    float f = 3.0; // convert double to float
    long double ld = 3.0; // convert double to long double

    int i = 3.5; // convert double to int

    double d = 3; // convert int to double

    bool b1 = 3; // convert int to bool
    bool b2 = 3.0; // convert double to bool
    


    return 0;
}