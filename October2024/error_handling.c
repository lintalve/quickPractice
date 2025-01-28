#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    //variables go in the beginning of the scope
    FILE *file = fopen("nonexistent.txt", "r");
    //error handling piece of code
    //kind of like with require, but proper c
    if (!file) {
        printf("Error opening file bitches: %s\n", strerror(errno));
        return 1;     //returning 1 (error code in c) from main();
    }
    fclose(file);
    return 0;
}

