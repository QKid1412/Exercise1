
#include <stdio.h>

int main(){
    int height, length, width, volume, weight;

    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter length of box: ");
    scanf("%d", &length);
    printf("Enter width of box: ");
    scanf("%d", &width);

    volume = height * length * width;
    weight = (volume+165)/166;

    printf("Volume: %d\n", volume);
    printf("Weight: %d\n", weight);

    return 0;
}
