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
        // gestione del danno sulla base dei vari tipi
        
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