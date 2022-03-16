#include "pokemon_battle.h"
#include "common.h"

using namespace std;

int main()
{
  // Charmander
  PokemonMove scratch = PokemonMove("Scratch", 35, 40, moveCategory::physicalMove, "normal");
  PokemonMove ember = PokemonMove("Ember", 25, 40, moveCategory::specialMove, "fire");

  Pokemon charmander = Pokemon("Charmander", {"fire"}, 52, 43, 60, 50, 65, 390, {scratch, ember});

  // Squirtle
  PokemonMove tackle = PokemonMove("Tackle", 35, 40, moveCategory::physicalMove, "normal");
  PokemonMove water_gun = PokemonMove("Water Gun", 25, 40, moveCategory::specialMove, "water");

  Pokemon squirtle = Pokemon("Squirtle", {"water"}, 48, 65, 50, 64, 43, 440, {tackle, water_gun});

  // Bulbasaur
  PokemonMove vine_whip = PokemonMove("Vine Whip", 25, 45, moveCategory::specialMove, "grass");

  Pokemon bulbasaur = Pokemon("Bulbasaur", {"grass"}, 49, 49, 65, 65, 45, 450, {tackle, vine_whip});

  // Pikachu
  PokemonMove nuzzle = PokemonMove("Nuzzle", 20, 20, moveCategory::physicalMove, "electric");

  Pokemon pikachu = Pokemon("Pikachu", {"electric"}, 55, 40, 50, 50, 90, 350, {nuzzle});


  PokemonTrainer player = PokemonTrainer({charmander, bulbasaur});
  PokemonTrainer enemy = PokemonTrainer({squirtle, pikachu});

  PokemonBattle battle = PokemonBattle(player, enemy);

  battle.battleLoop();
  

  return 0;
}