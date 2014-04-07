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
	char c;
	char name[45]; //length of the longest english word
	int i = 0;
    int count = 0;
	int found_word = 0;
	GList* list = NULL;
    GList* l = NULL;

	while ((c =fgetc(in_file)) != EOF ) {
        //if it's an alpha, convert it to lower case
        if (isalpha(c))
        {
            found_word = 1;
            c = tolower(c);
            name[i] = c;
            i++;
        }
        else {
            if (found_word) {
            	name[i] ='\0';
                for (l = list; l != NULL; l = l->next) {
                    if (strcmp(((Word*)l->data)->name, name)==0) {
                        ((Word*)l->data)->occurances++;
                        count++;
                    }
                }

                if (count == 0) {
                    Word *first = make_word(strdup(name), 1);
                    list = g_list_append(list, first);
                } else {
                    count = 0;
                }

                i = 0;
                found_word=0;
                name[0] = '\0';
            }
        }
	}
	print_list(list);
    g_list_foreach(list, (GFunc)g_free, NULL);
    g_list_free(list);
}

int main(int argc, char** argv) {
	FILE *in_file = fopen("paragraph.txt", "r");

	parse(in_file);

 	fclose(in_file);

	return 0;
}