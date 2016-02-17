#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) 
{
    char buffer[150];
    FILE * fptr;
    fptr = fopen("level.txt", "r");
    while (fgets(buffer, 150, fptr) != NULL) 
    {
        printf("%s\n", buffer);
    }
    return 0;
}
