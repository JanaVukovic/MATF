.intel_syntax noprefix

.text

.global bits

bits:
    enter 0, 0
    mov esi, 0
    mov rax, rdi
    mov rdx, 0
    mov ecx, 2
    mov rbx, 0

    petlja:
    cmp rax, 0
    je kraj
    xor rdx, rdx
    div ecx
    cmp edx, 1
    je dodaj
    jmp petlja

    kraj:
    mov rax, rbx
    xor rdx, rdx
    div ecx
    mov rax, rdx
    leave
    ret

    dodaj:
    inc rbx
    jmp petlja
