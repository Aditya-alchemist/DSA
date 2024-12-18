#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "DSA_LAB";
    char temp;
    char *start, *end;

    printf("Original string: %s\n", str);

    start = str;                     
    end = str + strlen(str) - 1;    
    
    while (start < end) {
        temp = *start;  
        *start = *end;
        *end = temp;

        start++; 
        end--;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}
