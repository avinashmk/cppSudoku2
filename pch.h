// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

// DEBUG_ENABLED
// true if Debug statements are to be enabled.
// false by default.
constexpr bool DEBUG_ENABLED = false;

// FANCY_PRINT
// true to keep printing the working solution set.
// false by default.
// Huge performance impact -- 1 second computation takes 1 hour(or more).
constexpr bool FANCY_PRINT = false;

// SHUFFLE_ENTRIES
// true to shuffle entry set used in each recursion.
// false (recommended).
constexpr bool SHUFFLE_ENTRIES = false;

// USE_MT_ENGINE
// MT engine generates a random set of entries with every execution.
// Due to not impact performance, the MT engine is used to randomize only genesis entry set.
// true to shuffle (recommended).
constexpr bool USE_MT_ENGINE = true;

constexpr bool SHOW_PROGRESS_BAR = true;

// TODO: add headers that you want to pre-compile here

#endif //PCH_H
