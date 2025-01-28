#include "dynoArray.h"

int main(int argc, const char* argv[]) {
    darray da;
    da_initialise(&da, SIZE);
    da_append(&da, 354.765f);
    da_append(&da, 563.65f);
    da_append(&da, 78.75f);
    printf("float is %f\n", *(da.storage)); //prints   354.339999
    printf("float is %g\n", *(da.storage + 2));
    return 0;
}

