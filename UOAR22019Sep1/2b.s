.intel_syntax noprefix

.text

.global stranice

stranice:
enter 0, 0
    mov rax, 0
    mov r9, 0
    prtlja:
    cmp r9, rcx
    je krajka
    mov r10d, [rdi + 4*r9]
    mov r11d, [rsi + 4*r9]
    mov r12d, [rdx + 4*r9]
    push rax
    push rdi
    push rsi
    push rdx
    push rcx
    push r9

    mov rdi, r10
    mov rsi, r11
    mov rdx, r12
    call trougao
    mov r10d, eax

    pop r9
    pop rcx
    pop rdx
    pop rsi
    pop rdi
    pop rax
    add rax, r10
    inc r9
    jmp prtlja
    krajka:
    leave
    ret
