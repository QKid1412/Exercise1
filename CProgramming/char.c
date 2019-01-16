#include <stdio.h>

int main(){
    // while (getchar() != '\n'); //skips rest of line

    /*
    int i, command;
    printf("Enter an integer: ");
    scanf("%d", &i);
    printf("Enter a command: ");
    command = getchar();

    //  scanf leaves behind characters not consumed during the reading of i (eg. \n);
        getchar fetches the first leftover character(eg. new-line '\n', and not getting what we want).
    */


    /* Calculate length of message
    int length = 0;

    printf("Enter a message: ");

    while(getchar() != '\n'){
        length ++;
    }

    printf("The length is: %d", length);
    */


    //Chap 7. Exercise 5
    int sum = 0;
    char ch;

    printf("Enter a word: ");

    while ((ch = getchar()) != '\n')
        switch (toupper(ch)) {
        case 'D': case 'G':
            sum += 2; break;
        case 'B': case 'C': case 'M': case 'P':
            sum += 3; break;
        case 'F': case 'H': case 'V': case 'W': case 'Y':
            sum += 4; break;
        case 'K':
            sum += 5; break;
          case 'J': case 'X':
            sum += 8; break;
        case 'Q': case 'Z':
            sum += 10; break;
        default:
            sum++; break;
        }

    printf("Scrabble value: %d\n", sum);


    return 0;
}

