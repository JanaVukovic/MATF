.intel_syntax noprefix

.text

.global stepen

stepen:
    enter 0, 0
    mov rax, 1

    petlja:
    cmp rsi, 0
    je kraj
    xor rdx, rdx
    mul rdi
    dec rsi
    jmp petlja

    kraj:
    leave
    ret
