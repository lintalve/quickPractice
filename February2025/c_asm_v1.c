#include <stdio.h>

int main() {
    const char msg[] = "Hello, Assembly!\n";
    size_t len = sizeof(msg) - 1;  // Length of message (excluding null terminator)

    __asm__ volatile (
        "mov rax, 1\n"         // syscall number for write (1)
        "mov rdi, 1\n"         // file descriptor 1 (stdout)
        "mov rsi, %[str]\n"    // pointer to string  //pointer to a string as a rule goes to rsi
        "mov rdx, %[len]\n"    // message length
        "syscall"              // invoke system call
        :
        : [str] "r"(msg), [len] "r"(len)  // Input operands
        : "rax", "rdi", "rsi", "rdx"      // Clobbered registers
    );

    return 0;
}


/*
gcc -no-pie -masm=intel -o asm_output asm_output.c
./asm_output
*/

#include <stdio.h>

int main() {
    char buffer[16];  // Local array on the stack

    __asm__ volatile (
        "mov byte ptr [%0], 'H'    \n"  //   buffer[0] = 'H'
        "mov byte ptr [%0+1], 'i'  \n"  //   buffer[1] = 'i'
        "mov byte ptr [%0+2], '!'  \n"  //   buffer[2] = '!'
        "mov byte ptr [%0+3], 0    \n"  //   buffer[3] = '\0' (null terminator)
        :
        : "r"(buffer)  // Input: buffer address
        : "memory"     // Clobbers (modifies memory)
    );

    printf("%s\n", buffer);  // Output: Hi!

    return 0;
}
/*
gcc -masm=intel -o asm_stack_alloc asm_stack_alloc.c
./asm_stack_alloc
*/

