#include <print>
#include "one.hpp"

/*
 *  Who does what: compiler vs linker
 * The compiler processes each .cpp file separately → each is its own translation unit (TU).
 * The compiler doesn’t see other .cpp files — it only sees what’s in the current TU (plus included headers).
 * If you declare something extern, the compiler doesn’t complain that there’s no definition yet.
 * Later, during the linking stage, the linker takes all object files and connects external references (extern names) to their actual definitions (symbols that do have storage).
 */

const int someConstInt = 36423;

int main() {
    
    const int* const ptr = &someConstInt;
    
    std::print("{}\n", *ptr);
    return 0;
}
