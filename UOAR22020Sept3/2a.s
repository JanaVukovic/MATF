.intel_syntax noprefix

.text

.global uzastopni
#(int *a, int *b, int* c, unsigned n)
#  Ci = max{(Ai + Ai+1), (Bi, Bi+1)}
#  rdi    rsi     rdx    rcx

uzastopni:
    enter 0, 0
    mov r8, 0
    mov r9, 1
petlja1:
    cmp r9, rcx
    je kraj1
    mov r10d, [rdi + r8*4]
    mov r11d, [rdi + r9*4]
    add r10, r11
    mov r11d, [rsi + r8*4]
    mov r12d, [rsi + r9*4]
    add r11, r12
    cmp r10d, r11d
    jg ajeveci
    mov [rdx + 4*r8], r11d
    inc r8
    inc r9
    jmp petlja1
ajeveci:
    mov [rdx + 4*r8], r10d
    inc r8
    inc r9
    jmp petlja1
kraj1:
    leave
    ret
