.text

.align 2

.global izraz

izraz:
    push {fp, lr}
    mov fp, sp
    mov r4, #4
    push {r5}
    mul r5, r0, r4
    sub r0, r5, r1
    add r0, r0, #1
    push {r2}
    mov r1, #2
    bl __divsi3
    pop {r2}
    mov r1, r2
    mul r3, r1, r2
    mov r2, r3
    mul r1, r2, r3
    add r0, r0, r1
    mov sp, fp
    pop {fp, pc}
