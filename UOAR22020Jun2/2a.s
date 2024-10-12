.intel_syntax noprefix

.text

.global prost

prost:
    enter 0,0
    mov rcx, 2
    mov r10, 1
pertla:
    cmp rcx, rdi
    jae kraj
    mov rax, rdi
    xor rdx, rdx
    div rcx
    cmp rdx, 0
    je nijeprost
    inc rcx
    kraj:
    mov rax, r10
    leave
    ret
    nijeprost:
    mov r10, -1
    jmp kraj
