//Colin Aslett, Main File for Zuul, C++ Period 07
#include <iostream>
#include "item.h"
#include "room.h"
#include <vector>
#include <cstring>
//https://www.sgi.com/tech/stl/Map.html
using namespace std;
void inv(vector<item*> &itema);
//losing condition, you go into the room you lose in
int main(){ 
  vector<item*> itema;
  vector<room*> rooma;
  bool pop = true;
  //items
  item* flashlight = new item("it shines light on dark objects", false);
  item* key = new item("A key to...nothing!", false);
  item* realkey = new item("A working key!", false);
  item* stick = new item("it's just a stick", false);
  item* litpaper = new item("Your lit paper that you got a F on...", false);
  //rooms
  room* yourroom = new room("Your room");
  room* hallway = new room("the hallway");
  room* bathroom = new room("its a bathroom!");
  room* playroom = new room("don't trip");
  room* kitchen = new room("pots and pans that you cant pick up");
  room* bonusroom = new room("there is a tv but no remote");
  room* garage = new room("No cars are here :(");
  room* basement = new room("don't go into the next room");
  room* ifyougoinhereyouwilllose = new room("WHAT DID I TELL YOU! NOW YOU GOTTA PLAY THIS ENTIRE GAME AGAIN!");
  room* attic = new room("dust and spiDERS!!!!");
  room* parentsbedroom = new room("Why are you in your parents room?");
  room* workroom = new room("Your father is looking at you, wondering what you are doing walking around the house");
  room* mainhallway = new room("very big hallway, maybe there is a door to the outside here?");
  room* adoor = new room("its a door to the outside! But do you have the key?");
  room* familyroom = new room("a room with couches but no people");
  //items in each room
  yourroom->itema.push_back(litpaper);
  playroom->itema.push_back(stick);
  kitchen->itema.push_back(key);
  garage->itema.push_back(realkey);
  basement->itema.push_back(flashlight);
  //exits for the rooms
  yourroom->exits["west"] = hallway;
  hallway->exits["west"] = playroom;
  hallway->exits["north"] = bathroom;
  hallway->exits["east"] = hallway;
  hallway->exits["south"] = kitchen;
  playroom->exits["north"] = attic;
  playroom->exits["south"] = parentsbedroom;
  attic->exits["south"] = playroom;
  parentsbedroom->exits["north"] = playroom;
  kitchen->exits["north"] = hallway;
  kitchen->exits["south"] = bonusroom;
  kitchen->exits["east"] = familyroom;
  bonusroom->exits["north"] = kitchen;
  bonusroom->exits["south"] = garage;
  garage->exits["north"] = bonusroom;
  garage->exits["south"] = basement;
  basement->exits["north"] = garage;
  basement->exits["south"] = ifyogoinhereyouwilllose;
  //do i need one for the losing room? maybe?
  familyroom->exits["west"] = kitchen;
  familyroom->exits["south"] = workroom;
  familyroom->exits["east"] = mainhallway;
  workroom->exits["north"] = familyroom;
  mainhallway->exits["west"] = familyroom;
  mainhallway->exits["south"] = adoor;
  
  while(pop == true){
    cout << "Welcome to Zuul, a game about a guy(or girl) that just wants to get outside";
    pop = false;
  }
}
void inv(vector<item*> &xd){
  
}
