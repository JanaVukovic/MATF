.intel_syntax noprefix

.text

.global armstrongovi
#int armstrongovi(unsigned* a, unsigned n)
#             rax         rdi      rsi

armstrongovi:
    enter 0,0
    mov rcx, 0
pertla:
    cmp rcx, rsi
    je endoftheworld
    mov r11d, [rdi + 4*rcx]
    push rdi
    push rcx
    push rsi
    mov rdi, r11
    call armstrong
    pop rsi
    pop rcx
    pop rdi
    cmp rax, -1
    je remove
    inc rcx
    jmp pertla
remove:
    mov r10, rcx
    mov r11, r10
    inc r11
begrem:
    cmp r11, rsi
    jae endrem
    mov r11d, [rdi + 4*r11]
    mov [rdi + 4*r10], r11d
    inc r10
    inc r11
    jmp begrem
endrem:
    dec rsi
    jmp pertla
endoftheworld:
    mov rax, rcx
    leave
    ret
