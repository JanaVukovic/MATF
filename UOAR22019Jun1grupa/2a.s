.intel_syntax noprefix

.text

.global izraz

izraz:
    enter 0,0
    mov rax, rdi
    xor rdx, rdx
    mul rsi
    mov rdi, 16
    xor rdx, rdx
    div rdi
    leave
    ret
