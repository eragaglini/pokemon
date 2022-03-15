#ifndef POKEMON_GAME_H
#define POKEMON_GAME_H

#include <vector>
#include <unordered_map>
#include "pokemon_trainer.h"
#include "common.h"


class PokemonBattle
{
private:
    /* data */
    PokemonTrainer *player;
    PokemonTrainer *enemy;
    std::unordered_map<std::string, std::unordered_map<std::string, double>> pokemon_types_map;

public:
    // constructor
    PokemonBattle(PokemonTrainer &_player, PokemonTrainer &_enemy);
    // destructor
    ~PokemonBattle();

    // getter methods
    std::unordered_map<std::string, std::unordered_map<std::string, double>> 
    GetPokemonTypesMap(void) const { return this->pokemon_types_map; }

    // battle loop
    void battleLoop();
};


#endif // GAME_H