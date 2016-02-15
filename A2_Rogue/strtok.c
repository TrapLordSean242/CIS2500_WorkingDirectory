#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include <ncurses.h>
void printGrids();
//void initCurses();
void parseLine(char* path);
void addDungeonElement(Rooms* room, DungeonElement* element);
int main(int argc, char* argv[])
{
  parseLine(argv[1]);
 // initCurses();
}
void parseLine(char* path)
{
    FILE * level;
    char buffer[150];
    char* stuff;
    DungeonElement* dunElement;
    Gold* typeGold;
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
	    if(stuff[0] != '\0')
	    {
	        sscanf(stuff, "%c%d%c%d", &dump, &stuffx, &comma, &stuffy);
	        printf("dump = %c, stuffx = %d, comma = %c, stuffy = %d\n",  dump,  stuffx,  comma,  stuffy );
	    }
	    else
	    {
	        sscanf(stuff, "%c%c%d", &dump, &direction, &stuffx);
	        printf("Dump = %c\n, Direction = %c\n, X = %d\n", dump, direction, stuffx);
	    }
	    switch(dump)
            {
	        case 'd':
	        dunElement = malloc(sizeof(DungeonElement));
                break;
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
                    printf("Height: %d\n", dunElement->x=room[roomCount-1]->width);
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
	    case 'g':
	    typeGold = malloc(sizeof(Gold));
	    typeGold->goldY=stuffx;
	    typeGold->goldX=stuffy;
	    printf("Gold X: %d\n", typeGold->goldX=stuffy);
            break;
            case 'M':
            dunElement->y=stuffx;
            dunElement->x=stuffy;
            dunElement->rep = 'M';
            dunElement->type = MONSTER;
            dunElement->next = NULL;
            room[roomCount-1]->numElements+=1;
            addDungeonElement(room[roomCount-1], dunElement);
            break;
            case 'h':
            dunElement->y=stuffx;
            dunElement->x=stuffy;
            dunElement->rep = 'h';
            dunElement->type = HERO;
            dunElement->next = NULL;
            room[roomCount-1]->numElements+=1;
            addDungeonElement(room[roomCount-1], dunElement);
            break;
            case 'p':
            dunElement->y=stuffx;
            dunElement->x=stuffy;
            dunElement->rep = 'p';
            dunElement->type = POTION;
            dunElement->next = NULL;
            room[roomCount-1]->numElements+=1;
            addDungeonElement(room[roomCount-1], dunElement);
            break;
	    default:
	    printf("Something went wrong!\n");
	    exit(0);
	    }
	    stuff = strtok(NULL, " ");
            //free(dunElement);
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
/*
void initCurses();
    Rooms* roomSize;
    roomSize = malloc(sizeof(Rooms*));
    int row = 140;
    int col = 150;
    initscr();
    getmaxyx(WINDOW*, row, col);
    printw("Scrren size is: %dX%d", row, col);
    move(2,0);
    free(Rooms*);

/*
void printGrids();

  int y;
  int x;
  int w;
  int h;
  int posy;
  int posx;
  for (int i=x; i<w+x; i++) {
        mvaddch(y, i, '#');
    }

    //THIS IS THE BUGGY LOOP
    for (int i=y; i<h+y; i++) {
        mvaddch(i, y, '#');
        mvaddch(i, w+x, '#');
    }

    for (int i=x; i<=w+x; i++) {
        mvaddch(h+y, i, '#');
    }
    printMsg("Printed one rectangle");
    getchar()
    while(input != 'q'){
        switch(getchar()){
        case 'w':
        posy--;
        break;
        case 's':
        posy++;
        break;
        case 'a':
        posx--;
        break;
        case 'd':
        posx++;
        break;
        default: 
        break;
}
}

/*void printMsg(const char* msg) {
    int x, y;
    getyx(stdscr, y, x);
    mvprintw(0,0,msg);
    move(y,x);
}*/

