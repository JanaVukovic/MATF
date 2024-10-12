.intel_syntax noprefix

.text

.global filtriraj
#void filtriraj(unsigned* A, unsigned* B, unsigned n, unsigned* C, unsigned* m)
#                 rdi          rsi         rdx           rcx             r8

filtriraj:
    enter 0,0
    mov r9, 0
    mov r10, 0
    mov r11, 4
    mov r12, rdx
petlja2:
    cmp r9d, r12d
    je krajj
    xor rdx, rdx
    mov eax, [rdi + 4*r9]
    div r11d
    cmp edx, 0
    ja dalje
    mov eax, [rsi + 4*r9]
    xor rdx, rdx
    div r11d
    cmp edx, 0
    ja dalje
    mov r13d, [rdi + 4*r9]
    mov r14d, [rsi + 4*r9]

    push rdi
    push rsi
    push rcx
    push r8
    push r9
    push r10
    push r11
    push r12

    mov edi, r13d
    mov esi, r14d
    call izraz

    pop r12
    pop r11
    pop r10
    pop r9
    pop r8
    pop rcx
    pop rsi
    pop rdi

    mov [rcx + 4*r10], eax
    inc r10
    inc r9d
    jmp petlja2

    krajj:
    mov [r8], r10
    leave
    ret
    dalje:
    inc r9d
    jmp petlja2
