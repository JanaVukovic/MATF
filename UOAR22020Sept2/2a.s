.intel_syntax noprefix

.text

.global saberi
#odlucila sam da protumacim ovo kao void saberi(unsigned *a, unsigned *b, unsigned* c, unsigned n)
#jer nista drugo nema smisla kako da saberem jedan broj???
# rdi rsi rdx rcx

saberi:
    enter 0, 0
    mov r10, 0
pocetak:
    cmp r10, rcx
    je finish
    mov r11d, [rdi + 4*r10]
    mov r12d, [rsi + 4*r10]
    add r11, r12
    mov [rdx + 4*r10], r11d
    inc r10
    jmp pocetak
finish:
    leave
    ret
