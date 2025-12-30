/*
Random Number Generation
    RNG is very useful in areas such as statistics, games, and cryptography. However, computers are designed to be predictable and deterministic.
    This makes it very difficult to generate truly random values with software, which is why computers can use algorithms that simulate randomness.

Algorithms
    An algorithm is a sequence of instructions that can be followed to solve some problem or produce a result.
    A stateful algorithm retains some information between calls, as opposed to a stateless one.
    State refers to the current values held by stateful variables.
    A deterministic algorithm always produces the same output for a given input.

Psuedo-RNG
    A pseudo-random number generator is an algorithm that produces a sequence of numbers whose properties simulate a random sequence of values.
    Each state is based on the previous one, and it is actually deterministic.
    
    A random seed is a value or set of values used as an initial state, which is used to produce the pseudo-random set of values.
    All values are deterministically calculated from the seed.

    The theoretical maximum number of unique sequences that a PRNG can generate is determined by the number of bits in the PRNG’s state
    Since the sequence is determined by the seed, however, practically the number of unique sequences depends on the number of unique seeds the program can generate.
    If a PRNG is not provided with enough bits of quality seed data, we say that it is underseeded.
    Characteristics of an ideal seed:
        The seed should contain at least as many bits as the state of the PRNG, so that every bit in the state of the PRNG can be initialized by an independent bit in the seed.
        Each bit in the seed should be independently randomized.
        The seed should contain a good mix of 0 and 1s distributed across all of the bits.
        There should be no bits in the seed that are always 0 or always 1. These “stuck bits” do not provide any value.
        The seed should have a low correlation with previously generated seeds.

    As of C++20, the Mersenne Twister algorithm is the only PRNG that ships with C++ that has both decent performance and quality.
    That being said, it is still somewhat outdated by modern standards, since its results can be predicted after seeing 624 generated numbers.
    Some other choices:
        The Xoshiro family and Wyrand for non-cryptographic PRNGs.
        The Chacha family for cryptographic (non-predictable) PRNGs.
*/



#include <iostream>

// For illustrative purposes only, don't use this.
// generates 100 pseudo-random 16-bit integers
unsigned int LCG16() // our PRNG
{
    static unsigned int s_state{ 0 }; // only initialized the first time this function is called

    // Generate the next number

    // We modify the state using large constants and intentional overflow to make it hard
    // for someone to casually determine what the next number in the sequence will be.

    s_state = 8253729 * s_state + 2396403; // first we modify the state
    return s_state % 32768; // then we use the new state to generate the next number in the sequence
}

int main()
{
    // Print 100 random numbers
    for (int count{ 1 }; count <= 100; ++count)
    {
        std::cout << LCG16() << '\t';

        // If we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }

    return 0;
}