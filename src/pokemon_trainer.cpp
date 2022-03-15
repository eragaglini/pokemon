# include "pokemon_trainer.h"

int PokemonTrainer::changePokemon() {
    for (size_t i = 0; i < this->getPokemons().size(); i++)
        {
        if (this->getPokemons()[i].IsAlive())
            std::cout << i << ": " << this->getPokemons()[i].GetName() << " ";
        }
    std::cout << std::endl;
    int x;
    std::cin >> x;
    x = Common::checkInput(x, (this->getPokemons().size()-1));
    std::cout << x << std::endl;
    return x;
};


int PokemonTrainer::usePokemonMove() {
      for (size_t i = 0; i < this->getCurrentPokemon()->GetMoves().size(); i++)
      {
        /* code to display pokemon moves along with indices */
        std::cout << i << ": " << this->getCurrentPokemon()->GetMoves()[i].GetName();
        if (i != (this->getCurrentPokemon()->GetMoves().size() -1)) {
          std::cout << ", ";
        }
      }
      std::cout << std::endl;
      int x;
      std::cin >> x;
      x = Common::checkInput(x, (this->getCurrentPokemon()->GetMoves().size()-1));
      return x;
};

PokemonTrainer::~PokemonTrainer()
{
}