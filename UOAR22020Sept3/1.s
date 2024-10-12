.text

.align 2

.global izraz
@         r0        r0 r1 r2
@  (a+b+c)^2 + 2a + 4b + 8c

izraz:
    push {fp, lr}
    mov fp, sp
    push {r4, r5}
    add r4, r0, r1
    add r4, r4, r2
    mul r5, r4, r4
    mov r4, #4
    add r0, r0, r0
    add r0, r0, r5
    mul r5, r1, r4
    add r0, r0, r5
    mov r4, #8
    mul r5, r2, r4
    add r0, r0, r5
    mov sp, fp
    pop {fp, pc}
