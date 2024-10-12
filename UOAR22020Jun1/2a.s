.intel_syntax noprefix

.text

.global suma_negativnih

suma_negativnih:
    enter 0, 0
    mov rcx, 0
    mov r8, 0
    petlja:
    cmp rcx, rsi
    je kraj
    mov r9d, [rdi + 4*rcx]
    inc rcx
    cmp r9d, 0
    jl dodaj
    jmp petlja
    kraj:
    mov rax, r8
    leave
    ret
dodaj:
    add r8 , r9
    jmp petlja
