#include "pokemon.h"
#include "common.h"

using namespace std;

int main()
{
  // Charmander
  PokemonMove scratch = PokemonMove("Scratch", 35, 40, moveCategory::physicalMove, "normal");
  PokemonMove ember = PokemonMove("Ember", 25, 40, moveCategory::specialMove, "fire");

  Pokemon charmander = Pokemon("Charmander", {"fire"}, 52, 43, 60, 50, 65, 39, {scratch, ember});

  // Squirtle
  PokemonMove tackle = PokemonMove("Tackle", 35, 40, moveCategory::physicalMove, "normal");
  PokemonMove water_gun = PokemonMove("Ember", 25, 40, moveCategory::specialMove, "water");

  Pokemon squirtle = Pokemon("Squirtle", {"water"}, 48, 65, 50, 64, 43, 44, {tackle, water_gun});
  return 0;
}