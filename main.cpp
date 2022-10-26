#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Gamebooter.h"
#include "Init.ini"
#include "Navigator.h"



int main()
{

  Navigator newone("testlevel.dat");
  //Navigator newone;
  newone.Create();


  return 0;



}

