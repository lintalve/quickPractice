#include <stdio.h>
#include <stdbool.h>

int main(void){
    struct someStruct0{
        float x;
        float y;
        char* name;
    }structures[] = {{24.56f, 35.76f, "shit"}, {125.56f, 679.76f, "crap"}, {567.56f, 345.76f, "motherfucker"}};   //agregate initializing

    for(int i=0; i<sizeof(structures)/sizeof(*structures); i++)
        printf("%f  %f  %s\n", structures[i].x, structures[i].y, structures[i].name);
    
    if(true) printf("%zu\n", sizeof(char));
    return 0;
}