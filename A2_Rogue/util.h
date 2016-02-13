#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ncurses.h"

typedef enum Goldsize
  {
    BIG = 0,
    SMALL,
  }Goldsize;

typedef enum Elements
  {
    WEAPON = 0,
    DOOR,
    MONSTER,
    STAIR,
    POTION,
  }Elements;

typedef struct Hero{
  int currentx;
  int currenty;
  int totalGold;
}Hero;

typedef struct Gold
{
  int goldX;
  int goldY;
  int value;
  Goldsize size;
}Gold;

typedef struct DungeonElement
{
  int x;
  int y;
  char rep;
  struct DungeonElement* next;
  Elements type;
}DungeonElement;

typedef struct Rooms
{
  int height;
  int width;
  int numElements;
  DungeonElement* elementHead;
  Gold* gDrops;
  int numgDrops;
}Rooms;
/*requirements:
-open a file
-parse room descriptions**
    -whole file
    -by lines
- initialize ncurses**
- draws level to screen**
-parse user input**
-update screen
-clean up ncurses
-print gold
-print inventory
-reload room
-validate a user move
-update hero gold
-update inventory
 */
/*
data rquirements:
-gold type
-hero
-inventory (linked list)
-door
-dungeon elements
-break these down into data-types
 */
