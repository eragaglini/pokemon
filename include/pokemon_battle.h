#ifndef POKEMON_GAME_H
#define POKEMON_GAME_H

#include "pokemon_trainer.h"
//#include "common.h"


class PokemonBattle
{
private:
    /* data */
    PokemonTrainer *player;
    PokemonTrainer *enemy;

public:
    // constructor
    PokemonBattle(PokemonTrainer &_player, PokemonTrainer &_enemy);
    // destructor
    ~PokemonBattle();

    // method to get trainer choices
    std::vector<int> getTrainerChoice(PokemonTrainer &trainer);

    // battle loop
    void battleLoop();
};


#endif // GAME_H