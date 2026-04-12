#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>

class GameCharacter
{
    // Private member variables to store character information
private:
    std::string characterName;
    std::string playerLastName;
    int health;
    int attackPower;
    int defenseRating;

    // Public member functions to access character information and perform actions
    // Constructor to initialize GameCharacter attributes
public:
// Constructor to initialize GameCharacter attributes
    GameCharacter(const std::string &characterName,
                  const std::string &playerLastName,
                  int health,
                  int attackPower,
                  int defenseRating);

    std::string getCharacterName() const;
    std::string getPlayerLastName() const;
    int getHealth() const;
    int getAttackPower() const;
    int getDefenseRating() const;

    void takeHit(int damage);
};

#endif // GAMECHARACTER_H
