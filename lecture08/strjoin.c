/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *tracks[] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};

/* Returns a heap-allocated string that contains the strings 
   from the given array, joined up with no spaces between.
*/
char *strjoin(char *array[], int n)
{
    //finding the size to allocate
    int size = 0;
    int k;
    for (k=0; k<n; k++)
    {
        size = size + strlen(array[k]);
    }

    char *word;
    word = (char *) malloc(size*sizeof(char));
    strcpy(word, array[0]);
    
    int i;
    for (i=1; i<n; i++)
    {
        word = strcat(word, array[i]);
    }
    return word;
}


int main (int argc, char *argv[])
{
    char *s = strjoin(tracks, 5);
    printf("%s\n", s);
    return 0;
}
