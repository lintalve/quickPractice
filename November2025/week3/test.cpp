#include <cstdio>
#include <cstdlib>

static const int size = 16;

int main(int argc, const char* argv[]) {
    

    unsigned char* ptr = (unsigned char*)malloc(size);
    for(int j=0; j<size; j++) printf("%i", *(ptr + j));
    puts("\n");
    for(int i=0; i<size; i++) *(ptr+i) = i;

    for(int k=0; k<size; k++) printf("%i", *(ptr + k));
    puts("\n");

    printf("%zu\n", sizeof(int*));
    return 0;
}