//Colin Aslett, Item file, C++ Period 07
#include <iostream>
#include "item.h"
using namespace std;

//description is info about item, picked is whether or not you have the object
item::item(char* newdescription, bool newpicked){
  description = newdescription;
  picked = newpicked;
}
char* item::getDescription(){//should Item be capitalized?
   return description;
}
