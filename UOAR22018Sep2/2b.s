.intel_syntax noprefix

.text

.global transformisi_niz

transformisi_niz:
    enter 0,0
    mov rcx, 0
    petlja2:
    cmp rcx, rsi
    je kraj2

    mov r9d, [rdi + 4*rcx]
    push rdi
    push rsi
    push rcx
    mov rdi, r9

    call prost
    mov r9d, eax

    pop rcx
    pop rsi
    pop rdi
    cmp r9d, 1
    je jeprost
    inc rcx
    jmp petlja2

    jeprost:
    mov r9, rcx
    mov r10, r9
    inc r10
    dur:
    cmp r9, rsi
    jae krajovog
    mov r11d, [rdi + 4*r10]
    mov [rdi + 4*r9], r11
    inc r9d
    inc r10d
    jmp dur
    krajovog:
    dec rsi
    jmp petlja2

    kraj2:
    mov rax, rcx
    leave
    ret
