#include <stdio.h>

int main(void){
    int month, day, year;

    printf("Enter date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month, &day, &year);

    printf("Dated this %d", day);

    switch (day) {
        case 1: case 21: case 31:
            printf("st"); break;
        case 2: case 22:
            printf("nd"); break;
        case 3: case 23:
            printf("rd"); break;
        default: printf("th"); break;
    }

    printf (" day of ");

    switch (month) {
        case 1: printf("Jan"); break;
        case 2: printf("Feb"); break;
        case 3: printf("Mar"); break;
        case 4: printf("Apr"); break;
        case 5: printf("May"); break;
        case 6: printf("Jun"); break;
        case 7: printf("Jul"); break;
        case 8: printf("Aug"); break;
        case 9: printf("Sep"); break;
        case 10: printf("Oct"); break;
        case 11: printf("Nov"); break;
        case 12: printf("Dec"); break;
        //default: printf("Invalid Month"); break;
    }
    printf(" 20%.2d.\n", year);
}
