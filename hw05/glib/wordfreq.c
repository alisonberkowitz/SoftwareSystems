/*
    Copyright 2014 Alison Berkowitz

    This program reads a text file, splits lines into words, and counts 
    the frequency of each word.
*/

#include <stdio.h>
#include <string.h>
#include <glib.h>

typedef struct word {
	char *name;
	int occurances;
} Word;

Word *make_word(char *name, int occurances) {
	Word *word = g_new(Word, 1);
	word->name = name;
	word->occurances = occurances;
	return word;
}

void print_iterator(Word *word) {
	printf("word: '%s', count: '%d'\n", word->name, word->occurances);
}

void print_list(GList *list){
	g_list_foreach(list, (GFunc)print_iterator, NULL);
}

void parse (FILE *in_file) {
	int c;
	int found_word = 0;
	GList* list = NULL;

	while ((c =fgetc(in_file)) != EOF ) {
        //if it's an alpha, convert it to lower case
        if (isalpha(c))
        {
            found_word = 1;
            c = tolower(c);
            char p = putchar(c);
            Word *first = make_word(strdup(&p), 0);
            list = g_list_append(list, first);
            //putchar(c);
        }
        else {
            if (found_word) {
                // putchar('\n');
                found_word=0;
            }
        }
	}
	print_list(list);
}

int main(int argc, char** argv) {
	FILE *in_file = fopen("paragraph.txt", "r");

	parse(in_file);
	
 	GList* list = NULL;

 	Word *first = make_word("Hello", 0);
 	Word *second = make_word("World", 0);
 	list = g_list_append(list, first);
 	list = g_list_append(list, second);

 	print_list(list);

 	g_list_foreach(list, (GFunc)g_free, NULL);
 	g_list_free(list);
 	fclose(in_file);

	return 0;
}