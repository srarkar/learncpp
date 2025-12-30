/*
Keywords and Identifiers
    Otherwise known as reserved words, keywords hold special meaning.
    Keywords, identifiers, and operators make up the entire C++ language, except for preprocessor commands

    Naming restrictions of identifiers:
        - The identifier can not be a keyword. Keywords are reserved.
        - The identifier can only be composed of letters (lower or upper case), numbers, and the underscore character. That means the name can not contain symbols (except the underscore) nor whitespace (spaces or tabs).
        - The identifier must begin with a letter (lower or upper case) or an underscore. It can not start with a number.
        - C++ is case sensitive, and thus distinguishes between lower and upper case letters. nvalue is different than nValue is different than NVALUE.
    
    Good Practice:
        - Match syntax to the existing program
        - Make the length of an identifier proportional to how specific and accessible the identifier is
        - It should be clear from the name what value the identifier holds
*/


// these must be on separate lines
#include <iostream>
#include <string>

int main() {

    // while all three of these are legal and distinct, only the first is conventional
    int value;
    int Value;
    int VALUE;


    // these are all valid, although some are a bit disorienting
    int x;
int                y;
            int
z;

    /* Not allowed!
    std::cout << "Hello
    world!";
    */

    // whitespace-separated quoted text is automatically concatenated
    std::cout << "Hello "
    "world!"; // prints "Hello world!"

    return 0;

}


/*
    A comprehensive keywords list through C++ 23:
        alignas
        alignof
        and
        and_eq
        asm
        auto
        bitand
        bitor
        bool
        break
        case
        catch
        char
        char8_t (since C++20)
        char16_t
        char32_t
        class
        compl
        concept (since C++20)
        const
        consteval (since C++20)
        constexpr
        constinit (since C++20)
        const_cast
        continue
        co_await (since C++20)
        co_return (since C++20)
        co_yield (since C++20)
        decltype
        default
        delete
        do
        double
        dynamic_cast
        else
        enum
        explicit
        export
        extern
        false
        float
        for
        friend
        goto
        if
        inline
        int
        long
        mutable
        namespace
        new
        noexcept
        not
        not_eq
        nullptr
        operator
        or
        or_eq
        private
        protected
        public
        register
        reinterpret_cast
        requires (since C++20)
        return
        short
        signed
        sizeof
        static
        static_assert
        static_cast
        struct
        switch
        template
        this
        thread_local
        throw
        true
        try
        typedef
        typeid
        typename
        union
        unsigned
        using
        virtual
        void
        volatile
        wchar_t
        while
        xor
        xor_eq
*/