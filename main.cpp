#include <iostream>

#include <iostream>

#include "Init.ini"

#include "Player.h"



int main()
{
  Layers *lay = new Layers;

  LevelMap *level = new LevelMap("hyuo", "level1.dat");

  Player pl1(level, lay, "hyuo", 10, 10, 1, 1);

  std::cout << "level created!" << std::endl;

  delete lay;
  delete level;


  return 0;



}

