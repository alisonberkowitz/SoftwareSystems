/*
    Copyright 2013 Alison Berkowitz

    This program reads a text file, splits lines into words, and counts 
    the frequency of each word.
*/

#include <stdio.h>
#include <glib.h>

typedef struct word {
	char *name;
	int occurances;
} Word;

Word *make_word(char *name, int occurances) {
	Word *word = malloc(sizeof(Word));
	word->name = name;
	word->occurances = occurances;
	return word;
}

int main(int argc, char** argv) {
	FILE *in_file = fopen("paragraph.txt", "r");
	
 	GList* list = NULL;
 	list = g_list_append(list, "Hello world!");
 	printf("The first item is '%s'\n", g_list_first(list)->data);

 	fclose(in_file);

	return 0;
}