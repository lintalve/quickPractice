section .data

section .bss

section .text
global _start         ; Declare _start as the entry point

_start:
        ; Syscall: mmap (allocate memory)
    mov rax, 9        ; Syscall number for mmap
    xor rdi, rdi      ; Address hint: NULL (kernel chooses address)
    mov rsi, 4096     ; Size: 4 KB (one page)
    mov rdx, 3        ; Protection: read + write (PROT_READ | PROT_WRITE)
    mov r10, 34       ; Flags: anonymous + private (MAP_ANONYMOUS | MAP_PRIVATE)
    xor r8, r8        ; File descriptor: not used with MAP_ANONYMOUS
    xor r9, r9        ; Offset: 0
    syscall           ; Call mmap

        ; Check if mmap failed (return value in RAX)
    cmp rax, -4095    ; Negative values (-errno) indicate failure
    jl mmap_failed

        ; Store allocated memory address in rbx (or any register)
    mov rbx, rax

        ; Syscall: exit (cleanly terminate program)
    mov rax, 60       ; Syscall number for exit
    xor rdi, rdi      ; Exit code: 0
    syscall           ; Call exit

mmap_failed:
        ; If mmap failed, exit with error code
    mov rax, 60       ; Syscall number for exit
    mov rdi, 1        ; Exit code: 1 (indicates error)
    syscall           ; Call exit
