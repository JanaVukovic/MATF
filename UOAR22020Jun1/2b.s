.intel_syntax noprefix

.text

.global suma
#       rax  rdi     rsi     rdx    rcx

suma:
    enter 0, 0
    push rdx
    push rcx
    call suma_negativnih
    mov r8, rax
    pop rcx
    pop rdx
    mov rdi, rdx
    mov rsi, rcx
    push r8
    call suma_negativnih
    mov r9, rax
    pop r8
    add r8, r9
    mov rax, r8
    mov r8, -1
    xor rdx, rdx
    imul r8
    leave
    ret
