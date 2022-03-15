#include "pokemon_battle.h"
#include <iostream>

typedef void(*FUNCPTR)(PokemonTrainer &trainer, int index); // our typedef

// some functions
void changePokemon(PokemonTrainer &trainer, int index) {
  Common::slow_print(trainer.getCurrentPokemon()->GetName() + " rientra!!");
  trainer.setCurrentPokemon(index);
  Common::slow_print("Vai " + trainer.getCurrentPokemon()->GetName() + " !!");
}

std::unordered_map<int, FUNCPTR> func_map = {{0, changePokemon}};

PokemonBattle::PokemonBattle(PokemonTrainer &_player, PokemonTrainer &_enemy)
{
    player = &_player;
    enemy = &_enemy;
    this->pokemon_types_map = Common::GetPokemonTypesMap();
}

PokemonBattle::~PokemonBattle()
{
}


std::vector<int> PokemonBattle::getTrainerChoice(PokemonTrainer &trainer)
{
    std::vector<int> choices;
    int first_choice = 0;
    int second_choice = 0;
    std::cout << "0: attack " << "1: change pokemon " << std::endl;
    std::cin >> first_choice;
    choices.push_back(first_choice);
    first_choice = Common::checkInput(first_choice, 1);
    switch(first_choice) {
        case 0:
            second_choice = trainer.usePokemonMove();
            break;
        case 1:
            second_choice = trainer.changePokemon();
            break;
    }
    choices.push_back(second_choice);
    return choices;
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
        Common::slow_print("Vai "+player->getCurrentPokemon()->GetName() + "!");
        Common::slow_print("Vai "+enemy->getCurrentPokemon()->GetName() + "!");

        Common::slow_print("Cosa deve fare " + player->getCurrentPokemon()->GetName() + "?");
        std::vector<int> player_choices = getTrainerChoice(*player);

        Common::slow_print("Cosa deve fare " + enemy->getCurrentPokemon()->GetName() + "?");
        std::vector<int> enemy_choices = getTrainerChoice(*enemy);

        if (player_choices[0] == 0 && enemy_choices[0] == 0)
        {
            /* i pokemon si attaccano */
            if (player->getCurrentPokemon()->GetSpeed() >= enemy->getCurrentPokemon()->GetSpeed())
            {
                /* code */
                Pokemon target = *enemy->getCurrentPokemon();
                player->getCurrentPokemon()->UsePokemonMove(player_choices[1], target);
                target = *player->getCurrentPokemon();
                enemy->getCurrentPokemon()->UsePokemonMove(enemy_choices[1], target);
            }
            else
            {
                /* code */
                Pokemon target = *player->getCurrentPokemon();
                enemy->getCurrentPokemon()->UsePokemonMove(enemy_choices[1], target);
                target = *enemy->getCurrentPokemon();
                player->getCurrentPokemon()->UsePokemonMove(player_choices[1], target);
            }
        }
        else {
            func_map[player_choices[0]](*player, player_choices[1]);
            func_map[enemy_choices[0]](*player, enemy_choices[1]);
        };

        player_pokemons = player->getPokemons();
        enemy_pokemons = enemy->getPokemons();
    }
}