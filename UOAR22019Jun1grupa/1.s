.intel_syntax noprefix

.text

.global iste_cifre

iste_cifre:
    enter 0, 0
    mov rax, rdi
    xor rdx, rdx
    mov r9, 10
    div r9
    mov r10d, edx
    mov r11d, 1
petlja:
    cmp rax, 0
    je kraj1
    xor rdx, rdx
    div r9
    cmp rdx, r10
    je petlja
    mov r11d, 0
    kraj1:
    mov eax, r11d
    leave
    ret
