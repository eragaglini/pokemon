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
    Common::slow_print("battaglia cominciata!!");
    std::vector<Pokemon> player_pokemons = player->GetPokemons();
    while (std::any_of(player_pokemons.begin(), player_pokemons.end(), [](Pokemon i) { return i.IsAlive(); }))
    {
        /* code */
        Common::slow_print("turno di battaglia");
        player->getCurrentPokemon()->TakeDamage(1000);

        player_pokemons = player->getPokemons();
    }
    Common::slow_print("battaglia terminata");
}