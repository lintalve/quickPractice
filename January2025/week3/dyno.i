
//should be global, to  live in global section
//and not to be erased in the end of the scope
typedef struct {
    void *data;
    size_t size;
    size_t capacity;
} floatDynoArray;

void floatDynoArray_init(floatDynoArray *array) {
    array->data = ((void *)0);   //0, NULL, nullptr since c++11, it is all can be binded to a pointer
    array->size = 0;
    array->capacity = 0;
}
void floatDynoArray_clear(floatDynoArray *array) {
    free(array->data);
    //array->data = ((void *)0);  //#define NULL ((void*)0)  this a macro so
    array->data = NULL;  //#define NULL ((void*)0)  this a macro
    array->size = 0;
    array->capacity = 0;
}
int floatDynoArray_resize(floatDynoArray *array, size_t new_capacity) {
    void *new_data = (void*)malloc(array->data, new_capacity * sizeof(void));
    //if (!new_data) return 0; /* Allocation failed */
    if (!new_data) exit(1); /* Allocation failed */
    array->data = new_data;
    array->capacity = new_capacity;
    return 1;   //returns one => returns bool
}
int floatDynoArray_push_back(floatDynoArray *array, void value) {
    if (array->size == array->capacity) {
        //first is for initial condition, second is an exponential increase due to some value of O or something
        size_t new_capacity = array->capacity == 0 ? 1 : array->capacity * 2;
        //function returns an int, that means it can be treat as boolean, 0 for false, 1 for true
        if (!floatDynoArray_resize(array, new_capacity)) return 0;
    }
    array->data[array->size++] = value;
    return 1;
}
void floatDynoArray_get(floatDynoArray *array, size_t index) {
    if (index >= array->size) {
        fprintf(__stderrp, "Index out of bounds\n");
        exit(1);
    }
    return array->data[index];
}
void floatDynoArray_set(floatDynoArray *array, size_t index, void value) {
    if (index >= array->size) {
        fprintf(__stderrp, "Index out of bounds\n");
        exit(1);    //
    }
    array->data[index] = value;
}
int main(int argc, const char* argv[]) {
    floatDynoArray fda;
    return 0;
}
