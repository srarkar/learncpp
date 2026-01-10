/*
Nested Types (Member Types)
    Class types support a type outside of data members and member functions.
    Nested types, also known as member types, are defined inside a class definition.
        Make sure they are defined at the top of the class type, since they must be fully defined before being used.

    Class types can also contain nested typedefs or type aliases.

    Classes are usually not defined inside other classes, since the nested classes cannot access the implicit this pointer.
        This is because nested classes are able to be instantiated independently of the outer class.
        However, because nested classes are members of the outer class, they can access any private members of the outer class that are in scope.
    Nested types can be forward declared inside the class, and defined in or outside of it.
        However, a nested type cannot be forward declared prior to the definition of the enclosing class.
*/

#include <iostream>
#include <string>
#include <string_view>

class Employee
{
public:
    using IDType = int;
	enum Type // fully qualified name is Employe::Type
	{
		janitor,
		intern,
		ceo,
	};

private:
    std::string m_name{};
    IDType m_id{};
    double m_wage{};

public:
    Employee(std::string_view name, IDType id, double wage)
        : m_name { name }
        , m_id { id }
        , m_wage { wage }
    {
    }

    const std::string& getName() { return m_name; }
    IDType getId() { return m_id; } // can use unqualified name within class
};

int main()
{
    Employee john { "John", 1, 45000 };
    Employee::IDType id { john.getId() }; // must use fully qualified name outside class

    std::cout << john.getName() << " has id: " << id << '\n';

    return 0;
}