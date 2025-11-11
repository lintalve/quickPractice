#include <stdio.h>

int anInt = 234;

void function() {
    anInt++;
}

int main(int argc, const char* argv[]) {
    anInt = 423;
    function();
    printf("anInt %i\n", anInt);
    return 0;
}