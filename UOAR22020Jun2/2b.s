.intel_syntax noprefix

.text

.global izbaci_proste
#         rax          rdi      rsi

izbaci_proste:
    enter 0, 0
    mov rcx, 0
    prtlja:
    cmp rcx, rsi
    je krajkaa
    mov r9d, [rdi + rcx*4]
    push rdi
    push rsi
    push rcx
    mov rdi, r9
    call prost
    pop rcx
    pop rsi
    pop rdi
    cmp eax, 1
    je izbacii
    inc rcx
    jmp prtlja

    krajkaa:
    mov rax, rcx
    leave
    ret

    izbacii:
    mov r10, rcx
    mov r11, r10
    inc r11
    dur:
    cmp r10, rsi
    je krajovog
    mov r9d, [rdi + 4*r11]
    mov [rdi + 4*r10], r9d
    inc r10
    inc r11
    jmp dur
    krajovog:
    dec rsi
    jmp prtlja
