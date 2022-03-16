#include "pokemon_battle.h"
#include "common.h"

using namespace std;

int main()
{
  // Charmander
  PokemonMove scratch = PokemonMove("Scratch", 35, 40, moveCategory::physicalMove, "Normal");
  PokemonMove ember = PokemonMove("Ember", 25, 40, moveCategory::specialMove, "Fire");

  Pokemon charmander = Pokemon("Charmander", {"Fire"}, 52, 43, 60, 50, 65, 39, {scratch, ember});

  // Squirtle
  PokemonMove tackle = PokemonMove("Tackle", 35, 40, moveCategory::physicalMove, "Normal");
  PokemonMove water_gun = PokemonMove("Water Gun", 25, 40, moveCategory::specialMove, "Water");

  Pokemon squirtle = Pokemon("Squirtle", {"Water"}, 48, 65, 50, 64, 43, 44, {tackle, water_gun});

  // Bulbasaur
  PokemonMove vine_whip = PokemonMove("Vine Whip", 25, 45, moveCategory::specialMove, "Grass");

  Pokemon bulbasaur = Pokemon("Bulbasaur", {"Grass"}, 49, 49, 65, 65, 45, 45, {tackle, vine_whip});

  // Pikachu
  PokemonMove nuzzle = PokemonMove("Nuzzle", 20, 20, moveCategory::physicalMove, "Electric");

  Pokemon pikachu = Pokemon("Pikachu", {"Electric"}, 55, 40, 50, 50, 90, 35, {nuzzle});


  PokemonTrainer player = PokemonTrainer({charmander, bulbasaur});
  PokemonTrainer enemy = PokemonTrainer({squirtle, pikachu});

  PokemonBattle battle = PokemonBattle(player, enemy);

  battle.battleLoop();

  return 0;
}