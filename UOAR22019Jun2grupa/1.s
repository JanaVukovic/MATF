.intel_syntax noprefix

.text

.global sve_jedinice

sve_jedinice:
    enter 0, 0
    mov rax, rdi
    mov r9d, 2
    mov r10d, 1
    petlja:
    cmp rax, 0
    je kraj
    xor rdx, rdx
    div r9d
    cmp edx, 1
    je petlja
    mov r10d, 0
    kraj:
    mov eax, r10d
    leave
    ret
