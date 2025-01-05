#include <string.h>
#include <stdbool.h>

typedef struct Attribute{
    int intValue;
    float floatValue;
    bool boolValue;
    char* name;
}attr;

void initialize(attr* a, char* name);
void nullify(attr* a);