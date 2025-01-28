#include <stdlib.h>
#include <stdio.h>

#define DEFINE_DYNAMIC_ARRAY(TYPE, NAME)                                    \
    typedef struct {                                                        \
        TYPE *data;                                                         \
        size_t size;                                                        \
        size_t capacity;                                                    \
    } NAME;                                                                 \
                                                                            \
    void NAME##_init(NAME *array) {                                         \
        array->data = NULL;                                                 \
        array->size = 0;                                                    \
        array->capacity = 0;                                                \
    }                                                                       \
                                                                            \
    void NAME##_clear(NAME *array) {                                        \
        free(array->data);                                                  \
        array->data = NULL;                                                 \
        array->size = 0;                                                    \
        array->capacity = 0;                                                \
    }                                                                       \
                                                                            \
    int NAME##_resize(NAME *array, size_t new_capacity) {                   \
        TYPE *new_data = (TYPE(*))malloc(array->data, new_capacity * sizeof(TYPE)); \
        if (!new_data) return 0; /* Allocation failed */                    \
        array->data = new_data;                                             \
        array->capacity = new_capacity;                                     \
        return 1;                                                           \
    }                                                                       \
                                                                            \
    int NAME##_push_back(NAME *array, TYPE value) {                         \
        if (array->size == array->capacity) {                               \
            size_t new_capacity = array->capacity == 0 ? 1 : array->capacity * 2; \
            if (!NAME##_resize(array, new_capacity)) return 0;              \
        }                                                                   \
        array->data[array->size++] = value;                                 \
        return 1;                                                           \
    }                                                                       \
                                                                            \
    TYPE NAME##_get(NAME *array, size_t index) {                            \
        if (index >= array->size) {                                         \
            fprintf(stderr, "Index out of bounds\n");                       \
            exit(EXIT_FAILURE);                                             \
        }                                                                   \
        return array->data[index];                                          \
    }                                                                       \
                                                                            \
    void NAME##_set(NAME *array, size_t index, TYPE value) {                \
        if (index >= array->size) {                                         \
            fprintf(stderr, "Index out of bounds\n");                       \
            exit(EXIT_FAILURE);                                             \
        }                                                                   \
        array->data[index] = value;                                         \
    }


//should be global, to  live in global section
//and not to be erased in the end of the scope
DEFINE_DYNAMIC_ARRAY(void, floatDynoArray)

int main(int argc, const char* argv[]) {
    floatDynoArray fda;
    
    return 0;
}

