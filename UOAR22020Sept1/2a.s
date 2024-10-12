.intel_syntax noprefix

.text

.global armstrong
#          rax=1/-1     rdi
armstrong:
    enter 0,0
    mov rcx, 0
    mov rax, rdi
    mov r10, 10
    mov r13, 0
    p:
    cmp rax, 0
    je dalje
    xor rdx, rdx
    div r10
    inc rcx
    jmp p

    dalje:
    mov rax, rdi
    petlja:
    cmp rax, 0
    je kraj
    xor rdx, rdx
    div r10
    jmp stepen
    stepen:
    push rax
    mov rax, 1
    mov r11, rdx
    mov r12, 0
    poc:
    cmp r12, rcx
    je krajstepena
    xor rdx, rdx
    mul r11
    inc r12
    jmp poc
    krajstepena:
    add r13, rax
    pop rax
    jmp petlja
    kraj:
    mov rax, r13
    cmp rdi, rax
    je jeste
    mov rax, -1
    krajj:
    leave
    ret
    jeste:
    mov rax, 1
    jmp krajj
