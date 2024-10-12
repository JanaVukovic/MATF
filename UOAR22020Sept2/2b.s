.intel_syntax noprefix

.text

.global saberi_neparne
#unsigned *a, unsigned *b, unsigned* c, unsigned n)
# rdi rsi rdx rcx

saberi_neparne:
    enter 0,0
    mov r10, 0
    mov r11, 2
prvi:
    cmp rcx, r10
    je drugipoc
    mov eax, [rdi + r10*4]
    push rdx
    xor rdx, rdx
    div r11
    cmp rdx, 1
    je neparanprvi
    pop rdx
    inc r10
    jmp prvi
neparanprvi:
    pop rdx
    mov r13, 0
    mov [rdi + 4*r10], r13d
    inc r10
    jmp prvi
drugipoc:
    mov r10, 0
drugi:
    cmp r10, rcx
    je sabiraj
    mov eax, [rsi + r10*4]
    push rdx
    xor rdx, rdx
    div r11
    cmp rdx, 1
    je neparandrugi
    pop rdx
    inc r10
    jmp drugi
neparandrugi:
    pop rdx
    mov r13, 0
    mov [rsi + 4*r10], r13d
    inc r10
    jmp drugi
sabiraj:
    call saberi
    leave
    ret
