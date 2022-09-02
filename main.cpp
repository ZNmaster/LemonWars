#include <iostream>

#include <iostream>

#include "Scanner.ini"

#include "Player.h"



int main()
{
  Layers *lay = new Layers;

  LevelMap *level = new LevelMap("hyuo", "level1.dat");

  std::cout << "level created!" << std::endl;

  delete lay;
  delete level;


  return 0;



}

