//COlin Aslett, Room file, C++ Period 07
#include <iostream>
#include "room.h"
using namespace std;

room::room(char* newdesc){
  desc = newdesc;
}
char* room::getDesc(){
  return desc;
}

//vector<room*>xd;
