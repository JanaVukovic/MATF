.intel_syntax noprefix

.text

.global polukvadrat
polukvadrat:
    enter 0, 0
    mov rax, rdi
    mul rax
    mov edi, 2
    div edi
    leave
    ret
