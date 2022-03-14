#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <string>
#include <vector>
#include <sstream> //istringstream
#include <fstream>
#include "common.h"

using namespace std;


void SplitString(std::string s, std::vector<std::string> &v){
	
	std::string temp = "";
	for(int i=0;i<s.length();++i){
		
		if(s[i]==';'){
			v.push_back(temp);
			temp = "";
		}
		else{
			temp.push_back(s[i]);
		}
		
	}
	v.push_back(temp);
	
}

std::unordered_map<std::string, std::unordered_map<std::string, double>> Common::GetPokemonTypesMap() {
    std::unordered_map<std::string, std::unordered_map<std::string, double>> pokemon_types_map;
    // setting up the pokemon types map
    std::ifstream csvFile;
    csvFile.open("pokemon_types.csv"); 
    if (csvFile.is_open())
    {
        std::string line;
        std::vector<std::string> type_keys;
        std::unordered_map<std::string, double> type_map;
        getline(csvFile, line);
        line.erase(0, line.find(";", 0)+1);
        SplitString(line, type_keys);
        while(getline(csvFile, line))
        {
            std::string type_name;
            std::unordered_map<std::string, double> type_map;
            std::vector<double> type_values;
            type_name = line.substr(0, line.find(";", 0));
            line.erase(0, line.find(";", 0)+1);
            std::string temp = "";
            for(int i=0;i<line.length();++i){
                if(line[i]==';'){
                type_values.push_back(std::stod(temp));
                temp = "";
                }
                else{
                temp.push_back(line[i]);
                }
            }
            type_values.push_back(std::stod(temp));
            for (size_t i = 0; i < type_values.size(); i++)
            {
                type_map.insert({type_keys[i], type_values[i]});
            }
            pokemon_types_map[type_name] = type_map;
        }
    }
    else 
    {
        std::cout << "Sorry, the file could not be openend." << std::endl;
    }
    return pokemon_types_map;
}

std::knuth_b rand_engine;
std::uniform_real_distribution<> uniform_zero_to_one(0.0, 1.0);

bool Common::random_bool_with_prob( double prob )  // probability between 0.0 and 1.0
{
    return uniform_zero_to_one(rand_engine) >= prob;
}

// https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer
int Common::checkInput(int x, int arr_length) {
    while(std::cin.fail() || (x > arr_length) || (x < 0)) {
          slow_print("Please, enter valid input");
          std::cin.clear();
          std::cin.ignore(256,'\n');
          std::cin >> x;
      }
      std::cout << x << std::endl;
      return x;
}


void Common::slow_print(const std::string& s) {
    // prints one character at a time
    // http://www.cplusplus.com/forum/general/87665/
    for(char c: s)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        std::cout << c << std::flush;
    }
    std::cout << std::endl;
}