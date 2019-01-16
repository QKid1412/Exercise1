
#include <stdio.h>

int bits(unsigned char v){
    int count_bits = 0;
    int mask = 1;

    while (mask <= v){
        if( v&mask ){
            count_bits++;
        }
        mask <<= 1;
    }
    return count_bits;

}
