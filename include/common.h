#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include<string>

// Common functions and data to share across all files.
namespace Common {
    // function to get an unordered map of all type weaknesses
    std::unordered_map<std::string, std::unordered_map<std::string, double>> GetPokemonTypesMap();
    // used to check probability of events (mostly for attack accuracy)
    bool random_bool_with_prob( double prob );
    // check the input is correct
    int checkInput(int x, int arr_length);
    // delay printing
    void slow_print( const std::string& s );
}

#endif // COMMON_H_INCLUDED