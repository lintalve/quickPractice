global _start          ; Declare _start as the entry point

section .text
_start:
    mov rax, 0x2000001 ; macOS syscall: sys_exit
    xor rdi, rdi       ; Exit code 0
    syscall            ; Call kernel
