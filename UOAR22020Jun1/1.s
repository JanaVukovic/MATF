.text

.align 2

.global obrni

obrni:
    push {fp, lr}
    mov fp, sp
    mov r1, r0
    mov r2, #0
p:
    cmp r1, #0
    beq kraj
    mov r2, r2, lsl #1
    mov r0, r1
    push {r1, r2}
    mov r1, #2
    bl __umodsi3
    mov r3, r0
    pop {r1, r2}
    add r2, r2, r3
    mov r1, r1, lsr #1
    b p
kraj:
    mov r0, r2
    mov sp, fp
    pop {fp, pc}
