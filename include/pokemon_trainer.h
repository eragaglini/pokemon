#ifndef POKEMON_TRAINER_H
#define POKEMON_TRAINER_H


#include "pokemon.h"
#include "common.h"

class PokemonTrainer
{
private:
    /* data */
    Pokemon * current_pokemon;
    std::vector<Pokemon> pokemons;

public:
    PokemonTrainer(std::vector<Pokemon> pokemons) : pokemons(pokemons) {     this->setCurrentPokemon(0); }
    ~PokemonTrainer();
    std::vector<Pokemon> GetPokemons(void) const { return this->pokemons; }
    Pokemon * getCurrentPokemon() const { return (this->current_pokemon); }
    void setCurrentPokemon(int index) { this->current_pokemon = &(this->pokemons[index]); }

    int changePokemon();
    int usePokemonMove();
};
#endif