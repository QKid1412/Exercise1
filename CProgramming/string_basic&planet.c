#include <string.h>
#include <stdio.h>

#define NUM_PLANETS 9

/* char *strcpy(char *s1, const char *s2); */

//strcpy cannot check if str2 can fit in str1

/* Safer way
    strncpy(str1, str2, sizeof(str1));

    even more safer:
    strncpy(str1, str2, sizeof(str1)-1);
    str1[sizeof(str1)-1] = '\0';
*/


/* size_t strlen(const char *s);*/

/* char *strcat(char *s1, const char *s2);
    appends s2 to s1, returns s1(pointer to resulting string)

    similar to strcpy, strncat is safer function to deal with length&str1's accomadation of str2
*/

/* int strcmp(const char *s1, const char *s2);
    e.g. abc < bcd; abc < abcd. Others, based on ASCII set.

 */

int main (int argc, char *argv[]){
    char *planets[] = {"Mercury", "Venus", "Earth",
                        "Mars", "Jupiter", "Saturn",
                        "Uranus", "Neptune", "Pluto"};

    int i,j;

    for(i = 1; i < argc; i++) {
        for(j = 0; j < NUM_PLANETS; j++){
            if(strcmp(argv[i], planets[j]) == 0){
                printf("%s is planet %d\n", argv[i], j+1);
                break;
            }
        }
        if (j == NUM_PLANETS){
            printf("%s is not a planet\n", argv[i]);
        }
    }
    return 0;
}
