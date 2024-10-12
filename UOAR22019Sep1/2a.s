.intel_syntax noprefix

.text

.global trougao
#    eax    rdi   rsi  rdx
trougao:
    enter 0, 0
    cmp rdi, 0
    jle nije
    cmp rsi, 0
    jle nije
    cmp rdx, 0
    jle nije
    mov rax, rdi
    add rax, rsi
    cmp rdx, rax
    jae nije
    mov rax, rdi
    add rax, rdx
    cmp rsi, rax
    jae nije
    mov rax, rsi
    add rax, rdx
    cmp rdi, rax
    jae nije
    mov rax, 1
    kraj:
    leave
    ret
    nije:
    mov eax, 0
    jmp kraj
