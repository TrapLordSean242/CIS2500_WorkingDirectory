#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "curses.h"

void parseLine(char* path);
//void storeDim();
//void storeItems();
//typedef struct roomDescrip {
//    int x; //rows
//    int y; //columns
//    roomItems[11]; 
//} roomDes[6];

//typedef struct runeScape{
//    int x;
//    int y;
//}runes;
int main(int argc, char* argv[])
{
  /*roomPtr* room;
    room = malloc(sizeof(roomPtr))
    //runesPtr* runes;
    //runes = malloc(sizeof(itemPtr))*/
  parseLine(argv[1]);


  //levelPars(room, runes);

  //free(roomPtr)
  //free(itemPtr)


  return 0;
}

void parseLine(char* path)
{
    char allFile[150];
    FILE *textFile;
    char* stuff;
    char* cstuff;
    int roomx;
    int roomy;
    int stuffx;
    int stuffy;
    char dump;
    char comma;
    textFile = fopen(path, "r");
    if(textFile == NULL)
    {
        printf("Error opening file");
        exit(0);
    }
    while(fgets(allFile, 150,textFile) != NULL);
    {
      printf("%s\n", allFile);
      /* get the dimensions of the room */
      stuff = strtok(allFile, " ");
      /* printf("%s\n", stuff); */
      /* sscanf(stuff, "%d%c%d", &roomx, &dump, &roomy); */

      /* /\* Parse the rest of the tokens *\/ */
      /* printf("%d %d\n", roomx, roomy); */
      /* stuff = strtok(NULL, " "); */
      while(stuff != NULL);
      {
	printf("%s\n", stuff);
	stuff = strtok(NULL, " ");
	/* if(stuff[0] != 'd') */
	/*   { */
	/*     sscanf(stuff, "%c%d%c%d", &dump, &stuffx, &comma, &stuffy);  */
	/*     printf("%c%d%c%d",  dump,  stuffx,  comma,  stuffy ); */
	/*   } */
	/* else */
	/*   { */
	/*   } */
      }
    }
}
    
    
    
    
    






