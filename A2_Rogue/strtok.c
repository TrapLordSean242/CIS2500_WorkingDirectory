#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

void parseLine(char* path);
void addDungeonElement(Rooms* room, DungeonElement* element);
int main(int argc, char* argv[])
{
  parseLine(argv[1]);
}
void parseLine(char* path)
{
  FILE * level;
  char buffer[150];
  char* stuff;
  DungeonElement* dunElement;
  int roomx;
  int roomy;
  int stuffx;
  int stuffy;
  int counter;
  char dump;
  char direction;
  char comma;
  Rooms** room;
  int roomCount;
  level = fopen(path, "r");
  roomCount = 0;
  if(level == NULL)
    {
      printf("Error opening file");
      exit(0);
    }
  room = malloc(sizeof(Rooms*));
  while(fgets(buffer, 150, level) != NULL);
  {
    roomCount++;
    room = realloc(room, sizeof(Rooms*)*roomCount);
    printf("%s\n", buffer);
    stuff = strtok(buffer, " ");
    sscanf(stuff, "%d%c%d", &roomx, &dump, &roomy);
    room[roomCount-1] = malloc(sizeof(Rooms));
    room[roomCount-1]->height=roomy;
    room[roomCount-1]->width=roomx;
    room[roomCount-1]->numgDrops=0;
    room[roomCount-1]->numElements=0;
    printf("roomx = %d, roomy = %d\n", roomx, roomy);

    stuff = strtok(NULL, " ");
    while (stuff != NULL)
      {
	if(stuff[0] != 'd')
	  {
	    sscanf(stuff, "%c%d%c%d", &dump, &stuffx, &comma, &stuffy);
	    printf("dump = %c, stuffx = %d, comma = %c, stuffy = %d\n",  dump,  stuffx,  comma,  stuffy );
	  }
	else
	  {
	    sscanf(stuff, "%c%c%d", &dump, &direction, &stuffx);
	    printf("Dump = %c\n, Direction = %c\n, X = %d\n", dump, direction, stuffx);
	  }
	switch(dump){
	case 'd':
	  dunElement = malloc(sizeof(DungeonElement));
	
	  switch(direction)
	    {
	    case 'n':
	      dunElement->y=0;
	      dunElement->x=stuffx;
	      break;
	    case 's':
	      dunElement->y=room[roomCount-1]->height;
	      dunElement->x=stuffx;
	      break;
	    case 'w':
		dunElement->y=stuffx;
	      dunElement->x=0;
	      break;
	    case 'e':
	      dunElement->y=stuffx;
	      dunElement->x=room[roomCount-1]->width;
	      break;
	    default:
	      printf("Something went wrong with room %d\n", roomCount);
	      exit(1);
	    }
	  dunElement->rep = 'd';
	  dunElement->type = DOOR;
	  dunElement->next = NULL;
	  room[roomCount-1]->numElements+=1;
	  addDungeonElement(room[roomCount-1], dunElement);
	    break;
	default:
	  printf("Something went wrong!\n");
	 exit(0);
	}
	stuff = strtok(NULL, " ");
      }
  }
}
void addDungeonElement(Rooms* room, DungeonElement* element)
{
  if(room || element == NULL)
    {
      return;
    }
  DungeonElement* curElement;
  if (room->elementHead == NULL)
    {
      room->elementHead = element;
    }
  else 
    {
      curElement = room->elementHead;
      while (curElement != NULL)
	{
	  if(curElement->next == NULL)
	    {
	      break;
	    }
	  curElement = curElement->next;
	}
      curElement->next = element;
    }

}
