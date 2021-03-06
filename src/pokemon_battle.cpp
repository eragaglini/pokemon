#include "pokemon_battle.h"

PokemonBattle::PokemonBattle(PokemonTrainer &_player, PokemonTrainer &_enemy)
{
    player = &_player;
    enemy = &_enemy;
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

typedef void(*FUNCPTR)(PokemonTrainer &trainer, int index); // our typedef

void switchPokemon(PokemonTrainer &trainer, int index) {
    Common::slow_print(trainer.getCurrentPokemon()->GetName() + " rientra!");
    trainer.setCurrentPokemon(index);
    Common::slow_print("Vai " + trainer.getCurrentPokemon()->GetName() + "!!" );
}

std::unordered_map<int, FUNCPTR> func_map = {{1, &switchPokemon}};


void PokemonBattle::battleLoop() {

    Common::slow_print("Comincia la battaglia!!");
    Common::slow_print("Vai "+player->getCurrentPokemon()->GetName() + "!");
    Common::slow_print("Vai "+enemy->getCurrentPokemon()->GetName() + "!");

    std::unordered_map<std::string, std::unordered_map<std::string, double>>  
    pokemon_types_map = Common::GetPokemonTypesMap();
    
    std::vector<Pokemon> player_pokemons = player->GetPokemons();
    std::vector<Pokemon> enemy_pokemons = enemy->GetPokemons();
    while (player_pokemons.size() > 0
    &&
    enemy_pokemons.size() > 0
    )
    {
        // get trainer choice
        Common::slow_print("Cosa deve fare " + player->getCurrentPokemon()->GetName() + "?");
        std::vector<int> player_choices = getTrainerChoice(*player);

        Common::slow_print("Cosa deve fare " + enemy->getCurrentPokemon()->GetName() + "?");
        std::vector<int> enemy_choices = getTrainerChoice(*enemy);

        
        // both pokemons attack
        if (player_choices[0] == 0 && enemy_choices[0] == 0) 
        {
            if (player->getCurrentPokemon()->GetSpeed() >= enemy->getCurrentPokemon()->GetSpeed()) {
                Pokemon * target = enemy->getCurrentPokemon();
                player->getCurrentPokemon()->UsePokemonMove(player_choices[1], *target, pokemon_types_map);
                if (target->IsAlive()) {
                    target = player->getCurrentPokemon();
                    enemy->getCurrentPokemon()->UsePokemonMove(enemy_choices[1], *target, pokemon_types_map);
                }
            }
            else
            {
                Pokemon * target = player->getCurrentPokemon();
                enemy->getCurrentPokemon()->UsePokemonMove(enemy_choices[1], *target, pokemon_types_map);
                if (target->IsAlive()) {
                    target = enemy->getCurrentPokemon();
                    player->getCurrentPokemon()->UsePokemonMove(player_choices[1], *target, pokemon_types_map);
                }
            }
        }
        else {
            if (player_choices[0] != 0) {
                func_map[player_choices[0]](*player, player_choices[1]);
                if (enemy_choices[0] == 0)
                {
                    Pokemon * target = player->getCurrentPokemon();
                    enemy->getCurrentPokemon()->UsePokemonMove(enemy_choices[1], *target, pokemon_types_map);
                }
                else
                {
                    func_map[enemy_choices[0]](*enemy, enemy_choices[1]);
                }
            }
            else {
                func_map[enemy_choices[0]](*enemy, enemy_choices[1]);
                Pokemon * target = enemy->getCurrentPokemon();
                player->getCurrentPokemon()->UsePokemonMove(player_choices[1], *target, pokemon_types_map);
            }
        }

        player_pokemons = player->GetPokemons();
        enemy_pokemons = enemy->GetPokemons();

        player_pokemons.erase( std::remove_if(player_pokemons.begin(), player_pokemons.end(), 
        [](Pokemon pokemon) { return !pokemon.IsAlive(); }), player_pokemons.end());
        
        enemy_pokemons.erase( std::remove_if(enemy_pokemons.begin(), enemy_pokemons.end(), 
        [](Pokemon pokemon) { return !pokemon.IsAlive(); }), enemy_pokemons.end());

        // se alla fine del turno uno dei due pokemon ?? ko, bisogna sostituirlo
        if (!player->getCurrentPokemon()->IsAlive() && player_pokemons.size() > 0)
        {
            /* code */
            Common::slow_print("Con chi vuoi sostituire " + player->getCurrentPokemon()->GetName() + " ?");
            int index = player->changePokemon();
            Common::slow_print(player->getCurrentPokemon()->GetName() + " basta cos??, rientra!");
            player->setCurrentPokemon(index);
            Common::slow_print("Vai " + player->getCurrentPokemon()->GetName());
        }
        if (!enemy->getCurrentPokemon()->IsAlive() && enemy_pokemons.size() > 0)
        {
            /* code */
            Common::slow_print("Con chi vuoi sostituire " + enemy->getCurrentPokemon()->GetName() + " ?");
            int index = enemy->changePokemon();
            Common::slow_print(enemy->getCurrentPokemon()->GetName() + " basta cos??, rientra!");
            enemy->setCurrentPokemon(index);
            Common::slow_print("Vai " + enemy->getCurrentPokemon()->GetName());
        }
        
    }
}