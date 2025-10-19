#include "two.hpp"

/*
 *  Who does what: compiler vs linker
 * The compiler processes each .cpp file separately → each is its own translation unit (TU).
 * The compiler doesn’t see other .cpp files — it only sees what’s in the current TU (plus included headers).
 * If you declare something extern, the compiler doesn’t complain that there’s no definition yet.
 * Later, during the linking stage, the linker takes all object files and connects external references (extern names) to their actual definitions (symbols that do have storage).
 */


//extern consts have storage for the linker to see them.
//that
extern const int someConstInt = 6543;
