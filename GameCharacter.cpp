#include "GameCharacter.h"
#include <iostream>

// Constructor to initialize GameCharacter attributes
GameCharacter::GameCharacter(const std::string& characterName,
                             const std::string& playerLastName,
                             int health,
                             int attackPower,
                             int defenseRating)
    : characterName(characterName),
      playerLastName(playerLastName),
      health(health),
      attackPower(attackPower),
      defenseRating(defenseRating) {
}

// Getter methods to access private member variables
std::string GameCharacter::getCharacterName() const {
    return characterName;
}

// Getter method to access player's last name
std::string GameCharacter::getPlayerLastName() const {
    return playerLastName;
}

// Getter method to access health
int GameCharacter::getHealth() const {
    return health;
}

// Getter method to access attack power
int GameCharacter::getAttackPower() const {
    return attackPower;
}

// Getter method to access defense rating
int GameCharacter::getDefenseRating() const {
    return defenseRating;
}

// Method to simulate taking a hit and reducing health accordingly
// This method takes an integer damage value, reduces the character's health by that amount,
// and prints out the character's name, the damage taken, and the new health value. 
// If the health drops to 0 or below, it also prints a message indicating that the character has
void GameCharacter::takeHit(int damage) {
    health -= damage;
    std::cout << ">>> " << characterName << " was hit with damage of " << damage << '\n';

    if (health < 0) {
        health = 0;
    }

    std::cout << "Health is now " << health << '\n';

    if (health == 0) {
        std::cout << characterName << " has been eliminated" << '\n';
    }
}
