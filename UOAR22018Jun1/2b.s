.intel_syntax noprefix

.text

.global transformisi_niz

transformisi_niz:
    enter 0, 0
    mov rcx, 0
petlja1:
    cmp rcx, rsi
    je kraj1
    mov r9d, [rdi + 4*rcx]
    push rdi
    push rsi
    push rdx
    mov edi, r9d
    mov esi, edx
    call stepen
    mov r9d, eax
    pop rdx
    pop rsi
    pop rdi
    mov [rdi + 4*rcx], r9d
    inc rcx
    jmp petlja1
kraj1:
    leave
    ret
