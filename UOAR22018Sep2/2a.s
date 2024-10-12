.intel_syntax noprefix

.text

.global prost

prost:
    enter 0, 0
    mov rcx, 1
    mov r9d, 1
    petlja:
    inc rcx
    cmp rcx, rdi
    jae kraj1
    mov rax, rdi
    xor rdx, rdx
    div rcx
    cmp edx, 0
    ja petlja
    mov r9, 0
    kraj1:
    mov rax, r9
    leave
    ret
