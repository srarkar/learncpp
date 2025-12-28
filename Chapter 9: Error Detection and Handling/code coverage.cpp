/*
Code Coverage
    Determining which tests are useful is beneficial in reducing the number of tests to write.
    
    Code coverage refers to how much of the source code is executed when testing, and there are multiple metrics for it.
        Statement coverage is the percentage of statements in code that have been exercised by the training suite.
        Branch coverage is the percentage of branches that have been executed. An if statement has 2 branches, for example, while a switch statement could have many more.
        Loop coverage, also known as the 0 1 2 test, says that if there is a loop in code, it should work when it iterates 0 times, 1 time, and 2 times
*/


/*
This reasonably requires 4 tests.
    The first should be passing in a vowel and verifying it returns true.
    The second should be passing in a consonant (that is not y).
    The third is passing in y as the first parameter and "true" as the second.
    The fourth is passing in y as the first parameter and "false" as the second.
*/
bool isLowerVowel(char c, bool yIsVowel)
{
    switch (c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return true;
    case 'y':
        return yIsVowel;
    default:
        return false;
    }
}