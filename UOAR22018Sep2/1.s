.intel_syntax noprefix

.text

.global stepen

stepen:
    enter 0, 0
    mov rax, 1
    mov rcx, 2
    petlja:
    cmp rax, rdi
    ja kraj
    xor rdx, rdx
    mul rcx
    jmp petlja
    kraj:
    leave
    ret
