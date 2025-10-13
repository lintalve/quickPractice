#include <stdbool.h>


class Attribute{
    int intValue;
    float floatValue;
    bool boolValue;
    const char* name;
public:
    Attribute(int a);
    Attribute(float a);
    Attribute(bool a);
    Attribute(char* a);
};

