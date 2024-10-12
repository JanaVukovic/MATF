.text

.align 2

.global izracunaj
@   r0                r0 r1 r2
@(-1)^n * (31*a - b - 4)

izracunaj:
    push {fp, lr}
    mov fp, sp
    push {r1, r2}
    mov r1, #2
    bl __umodsi3
    cmp r0, #0
    beq vece
    mov r0, #-1
    nastavi:
    pop {r1, r2}
    mov r3, #31
    mov r4, r1
    mul r1, r3, r4
    sub r1, r1, r2
    sub r1, r1, #4
    mov r2, r0
    mul r0, r1, r2
    mov sp, fp
    pop {fp, pc}

vece:
    mov r0, #1
    b nastavi
