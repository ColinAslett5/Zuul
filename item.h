#include <iostream>
#pragma once;
using namespace std;
class item{
 public:
  item(char* description, bool picked);
  char* getDescription();
  bool picked;
 private:
  char* description;
};
