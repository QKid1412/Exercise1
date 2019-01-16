#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char base64_map[] =
         		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        		"abcdefghijklmnopqrstuvwxyz"
                "0123456789+/";
size_t b64_length(size_t len);
void b64_encode(const void * src, size_t len, void * dst);

size_t b64_length(size_t len){
	size_t rest=len*8%6;
	size_t count=len*8/6;

	// if rest>0, need to return count+1 ( 1 more to store the rest part)
	return rest>0?count+1:count;
}

void b64_encode(const void * src, size_t len, void * dst){
    if (!src || !dst || len <= 0)
	{
		printf("empty ");
		return;
	}

	unsigned int *srccode = (unsigned int *)src;
	unsigned int num_of_padding = (len%3 == 0) ? 0 : 3-len%3;
	unsigned int num_of_rest = (len%3 == 0) ? 0 : 6 - len*8%6;
	*srccode <<= num_of_rest; // fill missing bits, eg. 11001100 -> 110011 000000

	unsigned char *dstcode = (char *)dst + b64_length(len) + num_of_padding;
    strcpy(dstcode, ""); //set *dst string end with null char \0
    size_t i,j;

    for(j = 0; j < num_of_padding; j++){
        char nextpad = '=';
        --dstcode;
        memset(dstcode, nextpad, sizeof(char));
    }

    for(i = 0; i < b64_length(len); i++){

        unsigned int nextbyte = *srccode & 0x3f;
        char nextchar = base64_map[nextbyte];

        --dstcode;
        memset(dstcode, nextchar, sizeof(char));

        *srccode = *srccode >> 6;
    }


}

int main()
{
	unsigned int inputcode = 0x0045f2;
	const unsigned int *src = &inputcode;
	size_t len = 3; // src len
	printf("%d\n", b64_length(len));

	char *dst = (char *)malloc(b64_length(len) + 1);
	b64_encode(src, len, dst);
	printf("%s", dst);
	free(dst);

	return (0);
}
/*
// C program to encode an ASCII
// string in Base64 format
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

// Takes string to be encoded as input
// and its length and returns encoded string
char* base64Encoder(char input_str[], int len_str)
{
    // Character set of base64 encoding scheme
    char char_set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    // Resultant string
    char *res_str = (char *) malloc(SIZE * sizeof(char));

    int index, no_of_bits = 0, padding = 0, val = 0, count = 0, temp;
    int i, j, k = 0;

    // Loop takes 3 characters at a time from
    // input_str and stores it in val
    for (i = 0; i < len_str; i += 3)
        {
            val = 0, count = 0, no_of_bits = 0;

            for (j = i; j < len_str && j <= i + 2; j++)
            {
                // binary data of input_str is stored in val
                val = val << 8;

                // (A + 0 = A) stores character in val
                val = val | input_str[j];

                // calculates how many time loop
                // ran if "MEN" -> 3 otherwise "ON" -> 2
                count++;

            }

            no_of_bits = count * 8;

            // calculates how many "=" to append after res_str.
            padding = no_of_bits % 3;

            // extracts all bits from val (6 at a time)
            // and find the value of each block
            while (no_of_bits != 0)
            {
                // retrieve the value of each block
                if (no_of_bits >= 6)
                {
                    temp = no_of_bits - 6;

                    // binary of 63 is (111111) f
                    index = (val >> temp) & 63;
                    no_of_bits -= 6;
                }
                else
                {
                    temp = 6 - no_of_bits;

                    // append zeros to right if bits are less than 6
                    index = (val << temp) & 63;
                    no_of_bits = 0;
                }
                res_str[k++] = char_set[index];
            }
    }

    // padding is done here
    for (i = 1; i <= padding; i++)
    {
        res_str[k++] = '=';
    }

    res_str[k] = '\0;';

    return res_str;

}


// Driver code
int main()
{
    char input_str[] = "MENON";
    int len_str = 4;

    // calculates length of string
    len_str = sizeof(input_str) / sizeof(input_str[0]);

    // to exclude '\0' character
    len_str -= 1;

    printf("Input string is : %s\n", input_str);
    printf("Encoded string is : %s\n", base64Encoder(input_str, len_str));
    return 0;
}
*/
