//COlin Aslett, room header file
#include <iostream>
#include <vector>
#include <map>
#include "item.h"
#include <cstring>
#pragma once;
using namespace std;
//this struct was from the website: https://www.sgi.com/tech/stl/Map.html
struct ltstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};

class room{
 public:
  room(char* desc);
  char* getDesc();
  vector<item*> itema;
  map<const char*,room*,ltstr> exits;
 private:
  char* desc;
};

//myRoom->xd.push_back(myitem);
