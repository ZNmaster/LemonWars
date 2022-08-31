#include <iostream>

#include <iostream>

#include "Scanner.ini"

#include "Player.h"



int main()
{
  Layers *lay = new Layers;

  LevelMap *level = new LevelMap("hyuo", "level1.dat");

  std::cout << "level created!" << std::endl;

  Player *player1 = new Player(level, lay, "player", 1, 1, 100, 100);

  delete player1;

  delete level;

  delete lay;


  return 0;



}

