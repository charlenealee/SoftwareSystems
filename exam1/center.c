/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Returns a heap-allocated string with length n, with
// the given string in the middle, surrounded by fillchar.
//
// For example, if s is allen, n is 10 and fillchar is .
// the result is ..allen... 

char *center(char *s, int n, char fillchar)
{	int i;
    int total = n;
	int diff;
    char *dest, *buf;
	int size =strlen(s);

//finds out difference in size of n and size of *s to calcuate 
//number of empty spots for fill char (accounts for 2 first spots)
	diff = n - size - 2;

//creates allocated size
    buf = (char *) malloc (total * sizeof(char));
    buf[0] = '\0';
    dest = buf;

//fills in first two fill char

	for (i=0; i< 3; i++){
		strcpy(dest, s[i]);
		dest+= fillchar;	
	}
	
	//copies over *s
	for (i=0; i< strlen(s); i++){
		strcpy(dest, s[i]);
		dest += strlen(s[i]);
	}
	
	//fills in all empty spots with fillchar for # diff spots 
	for (i=0; i < diff; i++){
		strcpy(dest, s[i]);
		dest+= fillchar;	
		}

    return buf;
}


int main (int argc, char *argv[])
{
    char *s = center("Software", 30, '.');
    printf("%s\n", s);

    char *s2 = center("Systems", 31, '-');
    printf("%s\n", s2);

    char *s3 = center("Spring 2014", 32, '*');
    printf("%s\n", s3);

    char *s4 = center("Exam 1", 33, '^');
    printf("%s\n", s4);

    return 0;
}
