#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 32

typedef struct{
    double x, y, z;
} Vector3;

typedef struct{
    float height;
    int age;
    const char* name;
    Vector3* vecP;
} Person;

void V_initialise1(Vector3* v) {
    puts("creating a Vector3");
    v->x=1.5;
    v->y=3.5;
    v->z=2.5;
}
void V_initialise2(Vector3* v, double a, double b, double c) {
    puts("creating a Vector");
    v->x = a;
    v->y = b;
    v->z = c;
}
void P_initialise1(Person* p, float h, int a, const char* n) {
    puts("creating a Person object");
    p->height = h;
    p->age = a;
    p->name = n;
    p->vecP = (Vector3*)malloc(sizeof(Vector3));
    V_initialise1(p->vecP);
}
void P_destroy1(Person* p) {
    puts("destroing a Person object\n\n");
    free(p->vecP);
}

int main(int argc, const char* argv[]) {
    Person* p1 = (Person*)malloc(sizeof(Person));
    if(p1) P_initialise1(p1, 183.5, 40, "Volodymyr");
    printf("Person: %s\n age: %d\n height: %f\n vector: (%f, %f, %f)\n\n",
        p1->name, p1->age, p1->height, p1->vecP->x, p1->vecP->y, p1->vecP->z);
    P_destroy1(p1);
    free(p1);
    
    
    Person* pArray = (Person*)calloc(SIZE, sizeof(Person));
    for(int i=0; i<SIZE; i++)
        P_initialise1(pArray + i * sizeof(Person), 183.5, 40, "Volodymyr");  //treat it as a pointer, with arithmetic
    for(int j=0; j<SIZE; j++)
        printf("(%f, %lf, %lf\n)", pArray[j*sizeof(Person)].vecP->x, pArray[j*sizeof(Person)].height, pArray[j*sizeof(Person)].height); //treating as an array
    
    free(pArray);
    
    
    return 0;
}
