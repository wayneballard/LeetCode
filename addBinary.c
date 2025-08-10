//
//  main.c
//  addbinary
//
//  Created by Ivan on 09.08.2025.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int ARRAY_SIZE = 10000;

typedef struct{
    char string_a[ARRAY_SIZE];
    char string_b[ARRAY_SIZE];
} Binary;


char* addBinary(Binary *b){
    printf("The input binary strings are: %s and %s\n", b->string_a, b->string_b);
    unsigned int room_a = 0;
    unsigned int room_b = 0;
    char* array = malloc(8*sizeof(unsigned int) + 1);
    
    if(strlen(b->string_a) >= strlen(b->string_b)){
        printf("The larger string is %s\n", b->string_a);
        for(int i = 0; i < strlen(b->string_a); i++){
            room_a <<= 1;
            if(b->string_a[i] == '1'){
                room_a ^= 1;
            }
        }
        printf("Decimal of the first string: %d\n", room_a);
        for(int j = 0; j < strlen(b->string_b); j++){
            room_b <<= 1;
            if(b->string_b[j] == '1'){
                room_b ^= 1;
            }
        }
        printf("Decimal of the second string: %d\n", room_b);
        unsigned int total = room_a + room_b;
        printf("The decimal for binary strings is: %d\n", total);
        for(int k = 8*sizeof(total) - 1; k >= 0; k--){
            printf("%d", ((total >> k) & 1));
            array[31 - k] = '0' + ((total >> k) & 1);
        }
            
        array[32] = '\0';
        unsigned int n = 0;
        while(array[n] != '1'){
            array[n] = ' ';
            n++;
        }
        memmove(array, array + n, strlen(array) + 1);
        printf("\n");
        
    }
    return array;
}

int main(int argc, const char * argv[]) {
    Binary binary = {.string_a = "1010", .string_b = "1011" };
    char* result = addBinary(&binary);
    printf("%s\n", result);
}
