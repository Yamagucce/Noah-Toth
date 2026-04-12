#include "GameCharacter.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
    // Read character data from file
    //infile is an input file stream object used to read data from the "characters.txt" file.
    std::ifstream infile("characters.txt");

    // Check if the file was opened successfully
    if (!infile) {
        std::cerr << "Error: could not open characters.txt" << std::endl;
        return 1;
    }

    // Vector to store pointers to GameCharacter objects
    std::vector<GameCharacter*> characters;
    std::string characterName;
    std::string playerLastName;
    int health;
    int attackPower;
    int defenseRating;

    // Read character data from the file and create GameCharacter objects
    while (infile >> characterName >> playerLastName >> health >> attackPower >> defenseRating) {
        GameCharacter* character = new GameCharacter(characterName, playerLastName, health, attackPower, defenseRating);
        characters.push_back(character);
    }

    // Display character information and simulate taking hits
    // Loop through each GameCharacter pointer in the vector and display their information
    // Simulate taking hits by calling the takeHit method with a damage value of 15
    for (GameCharacter* character : characters) {
        std::cout << "Character: " << character->getCharacterName()
                  << " " << character->getPlayerLastName()
                  << " | Health: " << character->getHealth()
                  << " | Attack: " << character->getAttackPower()
                  << " | Defense: " << character->getDefenseRating()
                  << std::endl;

        character->takeHit(15);
        std::cout << std::endl;
    }

    // Clean up dynamically allocated GameCharacter objects
    // Delete each GameCharacter object and clear the vector
    for (GameCharacter* character : characters) {
        delete character;
    }
    characters.clear();

    return 0;
}
