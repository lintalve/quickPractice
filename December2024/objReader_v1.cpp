#include <stdio.h>

namespace lint{

struct objReader {
    float positions[];
    float normals[];
    
    void readObj();
    void fillVBO();
};


};
