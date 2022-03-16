#include "pokemon.h"
#include "common.h"

PokemonMove::~PokemonMove()
{
}

void Pokemon::UsePokemonMove(int index, Pokemon & target, std::unordered_map<std::string, std::unordered_map<std::string, double>> 
    & pokemon_type_map) {
    if (this->moves[index].GetPowerPoints() > 0) {
        Common::slow_print(this->GetName() + " usa " + this->GetMoves()[index].GetName() + "!!");
        int damage = 0;
        if (this->moves[index].GetCategory() == moveCategory::physicalMove) {
            damage = this->moves[index].GetPower() * this->GetAttack() / target.GetDefense();
        }
        else {
            damage = this->moves[index].GetPower() * this->GetSpecialAttack() / target.GetSpecialDefense();
        }
        // se uno dei tipi del pokemon corrisponde a quello della mossa usata, moltiplica per 1.5
        double multiplier = 1;
        for (size_t i = 0; i < this->GetTypes().size(); i++)
        {
            /* code */
            if (this->GetTypes()[i] == this->moves[index].GetType())
            {
                /* code */
                multiplier *= 1.5;
            }
        }

        // gestione del danno sulla base dei vari tipi
        for (size_t i = 0; i < target.GetTypes().size(); i++)
        {
            /* code */
            multiplier *= pokemon_type_map[this->moves[index].GetType()][target.GetTypes()[i]];
        }

        if (multiplier >= 2)
        {
            /* code */
            Common::slow_print("E' superefficace!!");
        }
        else if (multiplier <= 0.5)
        {
            /* code */
            Common::slow_print("Non è molto efficace...");
        }
        damage *= multiplier;

        target.TakeDamage(damage);
        this->moves[index].SetPowerPoints(this->moves[index].GetPowerPoints() - 1);
    }
    else {
        Common::slow_print("La mossa non ha più pp disponibili!!!");
    }
};

void Pokemon::TakeDamage(const int hp) {
    if ((this->hp - hp) <= 0)
    {
        /* code */
        this->hp = 0;
        this->isAlive = false;
        Common::slow_print(this->GetName() + " è fuori combattimento!");
        return;
    }
    this->hp -= hp;
    return;
};

void Pokemon::Heal(const int hp) {
    if (this->IsAlive()) {
        if (this->hp == this->max_hp)
        {
            /* code */
            Common::slow_print("La salute di " + this->GetName() + " è già al massimo!!");
            return;
        }
        if ((this->hp + hp) <= this->max_hp)
        {
            /* code */
            this->hp += hp;
            return;
        }
        this->hp = this->max_hp;
        return;
    }
    Common::slow_print(this->GetName() + " è fuori combattimento!");
};



Pokemon::~Pokemon()
{
}