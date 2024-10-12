.intel_syntax noprefix

.text

.global faktorijel

faktorijel:
    enter 0, 0
    mov rax, 1
    p:
    cmp rdi, 0
    je kraj
    xor rdx, rdx
    mul rdi
    dec rdi
    jmp p
    kraj:
    leave
    ret
