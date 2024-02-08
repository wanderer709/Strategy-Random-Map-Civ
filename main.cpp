
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "conio.h"

void randomize();

int main()
{
    std::string game;

    int numberOfPlayers;

    std::cout << "Insert game, stupid: ";
    std::cin >> game;
    std::cout << game << "\n";

    std::cout << "Insert number of players, stupid: ";
    std::cin >> numberOfPlayers;
    std::cout << numberOfPlayers << "\n";

    std::ifstream mapsFile("./" + game + "/maps.txt");
    std::ifstream civsFile("./" + game + "/civs.txt");
    std::vector<std::string> maps;
    std::vector<std::string> civs;

    std::string map;
    std::string civ;

    while (getline(mapsFile, map))
    {
        if (map[0] != '/')
        {
            maps.push_back(map);
        }
    }

    while (getline(civsFile, civ))
    {
        if (civ[0] != '/')
        {
            civs.push_back(civ);
        }
    }

    randomize();

    std::string mapToPlay = maps[rand() % maps.size()];
    std::string civToPlay;
    std::vector<std::string> civsToPlay;

    for (int i = 0; i < numberOfPlayers; i++)
    {
        randomize();
        civToPlay = civs[rand() % civs.size()];
        civsToPlay.push_back(civToPlay);
    }

    std::cout << "Civs:\n";

    for (int i = 0; i < numberOfPlayers; i++)
    {
        std::cout << civsToPlay[i] << "\n";
    }

    std::cout << "Map: " + mapToPlay << "\n";

    getch();
    return 0;
}

void randomize()
{
    srand(time(NULL));
    srand(time(NULL) * rand());
}