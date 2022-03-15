#ifndef POKEMON_TRAINER_H
#define POKEMON_TRAINER_H

#include <vector>
#include "pokemon.h"
#include "common.h"

class PokemonTrainer
{
private:
    /* data */
    Pokemon * current_pokemon;
    std::vector<Pokemon> pokemons;

public:
    PokemonTrainer(std::vector<Pokemon> pokemons) : pokemons(pokemons) { this->current_pokemon = &(this->GetPokemons()[0]); }
    ~PokemonTrainer();
    std::vector<Pokemon> GetPokemons(void) const { return this->pokemons; }
    Pokemon * getCurrentPokemon() const { return (this->current_pokemon); }
    std::vector<Pokemon> getPokemons() const { return (this->pokemons); }

    int changePokemon();
    int usePokemonMove();
};
#endif