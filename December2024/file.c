#include <stdio.h>


int main(int argc, const char* argv[]) {
    FILE* fp;
    fp = fopen("cube.obj", "r");
    int c = fgetc(fp);
    printf("%c", c);
    return 0;
}
