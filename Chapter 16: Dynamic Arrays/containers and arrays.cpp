/*
Containers
    When dealing with multiple objects, it is inconvenient and repetitive to handle them individually. Instead, we use containers.
    Generally, a container is a datatype that stores a collection of unnamed objects known as elements.
        These elements are usually related in some way.
        For example, a string container holds a collection of characters, which can be outputted as text.
    These elements are unnamed so that the number of objects we can place in a container is not limited.
        If each element had to be named, it would be incredibly tedious, and defeat the purpose of a container.
        This is what distinguishes containers from other data structures. Structs, for examples, have named members.
    
    The number of elements in a container is its length or count.
    Containers typically have some subset of the following operations:
        Create a container (e.g. empty, with storage for some initial number of elements, from a list of values).
        Access to elements (e.g. get first element, get last element, get any element).
        Insert and remove elements.
        Get the number of elements in the container.

    Most languages support a variety of container types, each of which have strengths and limitations.

    Containers are usually homogenous, meaning the elements must all be of the same type.
    They are typically implemented as class templates in C++, allowing the user to provide the element type as a template type argument.

    The Containers library is a part of the C++ standard library that contains various class types that implement some common types of containers.
    A class type that implements a container is sometimes called a container class.
        Only the class types in the Containers library are considered to be containers in C++.
        This means that the following are considered to be containers in general but not under the C++ standard:
            C-style arrays
            std::string
            std::vector<bool>
*/

/*
Arrays
    An array is a container data type that stores its elements contiguously, meaning that sequential element exist in sequential/adjacent memory locations.
    They allow fast and direct access to any element.

    C++ contains three primary array types: (C-style) arrays, the std::vector container class, and the std::array container class.
    C-style arrays were inherited from C for backwards compatibility. They are sometimes known as "naked arrays”, “fixed-sized arrays”, “fixed arrays”, or “built-in arrays”.
        They are not preferred in modern usage due to strange and dangerous behavior.

    std::vector is the most flexible of the three primary array types 

    The std::array was created to replace the C-style arrays. It is more limited than std::vector, but can be more efficient (esp for smaller arrays).
    These types tend to have similar interfaces.
*/