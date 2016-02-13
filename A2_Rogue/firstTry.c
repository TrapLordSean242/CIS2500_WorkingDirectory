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
    char* allFile[150];
    FILE *textFile; 
    char* saveStuff[12];
    textFile = fopen(path, "r");
    if(textFile == NULL)
    {
        printf("Error opening file");
        exit(0);
    }
    while(fgets(allFile, 150,textFile) != NULL);
    {
        char* stuff = strtok(allFile, "X");
        printf("%s\n", stuff);
        stuff= strtok(NULL, ",");
        printf("%s\n", stuff);        
        while((stuff = strtok(NULL, " ")) != NULL);
        {
           char* cstuff = strtok(NULL, " ");
           cstuff = strtok (NULL, ",");
            //cstuff = strtok(NULL, "\n");
           printf("%s\n", cstuff);
      
        }
    }
}
    
    
    
    
    






