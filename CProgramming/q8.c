#include <stdio.h>
#include <stdlib.h>


struct s {
    float c;
    char arr[20];
    int a;
    int b;
};

struct s *get_ptr(int *a_ptr){
    return (struct s*)((char*)a_ptr - (int)&((struct s*)0)->a);
};

int main(){
    struct s *s_ptr = (struct s*)malloc(sizeof(struct s));
    s_ptr->a = 10;
    s_ptr->b = 29;
    struct s* result = get_ptr(&s_ptr->a);
    printf("function result address: %d\n", result);
    printf("original s_ptr address: %d\n", s_ptr);
    return 0;
}
