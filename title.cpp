//Colin Aslett, Main File for Zuul, C++ Period 07
#include <iostream>
#include "item.h"
#include "room.h"
#include <vector>
#include <cstring>
#include <map>
//https://www.sgi.com/tech/stl/Map.html
//http://www.cprogramming.com/tutorial/stl/stlmap.html
using namespace std;
void inv(vector<item*> &itema);
//losing condition, you go into the room you lose in
int main(){ 
  vector<item*> itema;
  vector<room*> rooma;
  vector<item*> inventory;
  bool pop = true;
  //items
  item* flashlight = new item("flashlight", false);
  item* key = new item("worthlesskey", false);
  item* realkey = new item("workingkey", false);
  item* stick = new item("stick", false);
  item* litpaper = new item("litpaper", false);
  //rooms
  room* yourroom = new room("Your room");
  room* hallway = new room("the hallway");
  room* bathroom = new room("its a bathroom!");
  room* playroom = new room("a playroom");
  room* kitchen = new room("a room with pots and pans that you cant pick up");
  room* bonusroom = new room("playroom, there is a tv but no remote");
  room* garage = new room("No cars are in this garage :(");
  room* basement = new room("Scary basement with a note: dont go into the next room!");
  room* youwilllose = new room("WHAT DID I TELL YOU! NOW YOU GOTTA PLAY THIS ENTIRE GAME AGAIN!");
  room* attic = new room("Attic: dust and spiDERS!!!!");
  room* parentsbedroom = new room("Why are you in your parents room?");
  room* workroom = new room("Your father is looking at you, wondering what you are doing walking around his workroom");
  room* mainhallway = new room("very big hallway, maybe there is a door to the outside here?");
  room* adoor = new room("its a door to the outside! But do you have the key?");
  room* familyroom = new room("a room with couches but no people");
  room* currentroom = new room("no desc");
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
  basement->exits["south"] = youwilllose;
  //do i need one for the losing room? maybe?
  familyroom->exits["west"] = kitchen;
  familyroom->exits["south"] = workroom;
  familyroom->exits["east"] = mainhallway;
  workroom->exits["north"] = familyroom;
  mainhallway->exits["west"] = familyroom;
  mainhallway->exits["south"] = adoor;
  //other variables
  currentroom = kitchen;
  cout << "Welcome to Zuul, a game about a guy(or girl) that just wants to get outside" << endl;
  while(pop == true){
    char stra[6];//exits
    char strx[10];//items
    cout << "You are currently in " << currentroom->getDesc() << endl;
    //exits
    cout << "There are exits:" << endl;
    for(map<const char*, room*, ltstr>::iterator i = currentroom->exits.begin();i != currentroom->exits.end();i++){
      cout << i->first << " , ";
    }
    cout << endl;
    //printing out items
    cout << "There are items:" << endl;
    for(vector<item*>::iterator i = currentroom->itema.begin();i != currentroom->itema.end();i++){
      cout << (*i)->getDescription() << endl;
    }
    //inventory
    cout << "Current inventory: " << endl;
    for(vector<item*>::iterator i = inventory.begin();i != inventory.end();i++){
      cout << (*i)->getDescription() << endl;
    }
    cout << "4 possible options('quit','move'.'pick','drop')" << endl;
    //picking/dropping item
    cin.getline(strx,10);
    if(strcmp(strx,"quit") == 0){
      pop = false;
      return 0;
    }
    if(strcmp(strx,"pick") == 0){
      char input[50];
      cout << "enter items name that you want to pick up" << endl;
      cin.getline(input,50);
      bool temp = false;
      for(vector<item*>::iterator i = currentroom->itema.begin();i != currentroom->itema.end();i++){
	if(strcmp(input,((*i)->getDescription())) == 0){
	  inventory.push_back(*i);
	  currentroom->itema.erase(i);
	  cout << "YOU PICKED IT UP!" << endl;
	  temp = true;
	  break;
	}
      }
      if(temp == false){
	cout << "YOU DIDN'T PICK IT UP!" << endl;
      }
    }
    if(strcmp(strx,"drop") == 0){

    }
    //to leave the room
    if(strcmp(strx,"move") == 0){
      cin.getline(stra,6);
      for(map<const char*, room*, ltstr>::iterator i = currentroom->exits.begin();i != currentroom->exits.end();i++){
	if(strcmp(stra,i->first) == 0){
	  currentroom = i->second;
	  break;
	}
	if(currentroom->exits.find(stra) == currentroom->exits.end()){
	  cout << "No such exit exists!" << endl;
	  break;//make sure that this works
	}
      }
    }
    //pop = false;
    if(currentroom == adoor){
      cout << "YOU WON!";
      pop = false;
      return 0;
    }
    //pop = false;
  }
}
void inv(vector<item*> &xd){
  
}
