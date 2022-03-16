#ifndef POKEMON_H_INCLUDED
#define POKEMON_H_INCLUDED
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

enum class moveCategory {physicalMove, specialMove};

class PokemonMove {
    private:
        std::string name;
        int power_points;
        int power;
        moveCategory category;
        std::string type;
    public:
        // constructor
        PokemonMove(const std::string name, const int power_points, 
        const int power, moveCategory category, std::string type) : 
        name(name), power_points(power_points), power(power),
        category(category), type(type) { }
        // destructor
        ~PokemonMove();
        int GetPowerPoints(void) const { return this->power_points; }
        int GetPower(void) const { return this->power; }
        std::string GetName(void) const { return this->name; }
        std::string GetType(void) const { return this->type; }
        moveCategory GetCategory(void) const { return this->category; }
};

class Pokemon {
    public:
        // constructor
        Pokemon(const std::string name, std::vector<std::string> types, 
        const int attack, const int defense,
        const int special_attack, const int special_defense, const int speed,
        const int max_hp, std::vector<PokemonMove> moves) : name(name), types(types), attack(attack), defense(defense), 
        special_attack(special_attack), special_defense(special_defense),
        speed(speed), max_hp(max_hp), hp(max_hp), moves(moves), isAlive(true) {  }
        // destructor
        ~Pokemon();
        // getter methods 
        std::string GetName(void) const { return this->name; }
        int GetAttack(void) const { return this->attack; }
        int GetDefense(void) const { return this->defense; }
        int GetSpecialAttack(void) const { return this->special_attack; }
        int GetSpecialDefense(void) const { return this->special_defense; }
        int GetSpeed(void) const { return this->speed; }
        int GetMaxHP(void) const { return this->max_hp; }
        int GetHP(void) const { return this->hp; }
        std::vector<std::string> GetTypes(void) const { return this->types; }
        std::vector<PokemonMove> GetMoves(void) const { return this->moves; }
        bool IsAlive(void) const { return this->isAlive; }

        // heal method
        void Heal(const int hp);
        // take damage
        void TakeDamage(const int damage);
        // use pokemon move
        void UsePokemonMove(int index, Pokemon & target, std::unordered_map<std::string, std::unordered_map<std::string, double>> 
        & pokemon_type_map);

    private:
        std::string name;
        int attack, defense, special_attack, special_defense, speed, hp, max_hp;
        std::vector<std::string> types;
        std::vector<PokemonMove> moves;
        bool isAlive;
};
#endif // POKEMON_H_INCLUDED