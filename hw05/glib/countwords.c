#include <glib.h>
#include <stdlib.h>
#include <stdio.h>

/* 

Charlene Lee
Written for Software Systems at Olin College


This program counts the frequency of words in Wuthering Heighs.
It uses a hash table and increases the value by testing to see if
that word has been counted yet or not. 


word_handler takes the book's text file and hash table as inputs.
fscanf checks each word by counting the whitespace.
hash table maintains a list of already checked words. 

If the word has already been accoutned for then, the frequency value
increases. Else, it skips it. 
*/


void check_word (FILE *file, GHashTable *hasher) {
	// word to check for
	char words[200]; //actual number of words 
 
	while (fscanf(file,"%s",words) != EOF) {
		//value will be null if there's no key for the word
		int value = g_hash_table_lookup(hasher, words);

		char *add_words = malloc(200);	// allocate space
		strcpy(add_words,words);
		if (value == NULL) {
			g_hash_table_insert(hasher, add_words, 1);
		} else {
			value++;
			g_hash_table_replace(hasher, add_words, value);
		}
	}
}



//count prints the word and its frequency
static void count (gpointer key, gpointer value, gpointer user) {
    printf("word: %s, freq: %i\n",key,value);
}


//main method to call to open up file and count words
int main() {
	FILE *file = fopen("wutheringheights.txt","r");
	GHashTable* hasher = g_hash_table_new(g_str_hash, g_str_equal);
	word_counter(file, hasher);
	g_hash_table_foreach(hasher, count, NULL);
	return 0;
	
	
}
	