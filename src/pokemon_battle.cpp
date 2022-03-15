#include "pokemon_battle.h"


PokemonBattle::PokemonBattle(PokemonTrainer &_player, PokemonTrainer &_enemy)
{
    player = &_player;
    enemy = &_enemy;
    this->pokemon_types_map = Common::GetPokemonTypesMap();
}

PokemonBattle::~PokemonBattle()
{
}

void PokemonBattle::battleLoop() {
    Common::slow_print("Comincia la battaglia!!");
    std::vector<Pokemon> player_pokemons = player->GetPokemons();
    std::vector<Pokemon> enemy_pokemons = enemy->GetPokemons();
    while (std::any_of(player_pokemons.begin(), player_pokemons.end(), [](Pokemon i) { return i.IsAlive(); })
    &&
    std::any_of(enemy_pokemons.begin(), enemy_pokemons.end(), [](Pokemon i) { return i.IsAlive(); })
    )
    {
        /* code */
        enemy->getCurrentPokemon()->TakeDamage(1000);

        player_pokemons = player->getPokemons();
        enemy_pokemons = enemy->getPokemons();
    }
    
}