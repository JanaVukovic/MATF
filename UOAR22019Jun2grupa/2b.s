.intel_syntax noprefix

.text

.global filtriraj
#extern void filtriraj(unsigned* a, unsigned* b, unsigned n, unsigned * c, unsigned *m)
#                          rdi        rsi          rdx          rcx               r8

filtriraj:
    enter 0, 0
    mov r9, 0
    mov r10, 0
petlja:
    cmp r9, rdx
    je kraj
    mov eax, [rsi + 4*r9]
    cmp eax, 1
    je posalji
    inc r9
    jmp petlja

    posalji:
    mov eax, [rdi + 4*r9]
    push rdi
    push rsi
    push rdx
    push rcx
    push r8
    push r9
    push r10

    mov rdi, rax
    call polukvadrat

    pop r10
    pop r9
    pop r8
    pop rcx
    pop rdx
    pop rsi
    pop rdi

    mov [rcx + r10*4], rax
    inc r10
    inc r9
    jmp petlja

    kraj:
    mov [r8], r10
    leave
    ret
