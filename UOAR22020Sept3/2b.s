.intel_syntax noprefix

.text

.global minus1
#minus1(int *a, int *b, int* c, unsigned n)
#        rdi     rsi       rdx     rcx

minus1:
    enter 0, 0
    mov r8, 0
    mov r10, -1
niza:
    cmp r8, rcx
    je dalje
    mov eax, [rdi + 4*r8]
    push rdx
    xor rdx, rdx
    imul r10
    pop rdx
    mov [rdi + 4*r8], eax
    inc r8
    jmp niza
dalje:
    call uzastopni
    leave
    ret
