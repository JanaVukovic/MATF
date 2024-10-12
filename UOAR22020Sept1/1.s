.text

.align 2

.global izracunaj

izracunaj:
push {fp, lr}
mov fp, sp

mov r3, #0
push {r4, r5}
mov r4, #1

prva:
cmp r3, r1
beq druga
mul r5, r4, r0
mov r4, r5
add r3, r3, #1
b prva

druga:
mov r1, r4
mov r4, #1
mov r3, #0
poc:
cmp r3, r2
beq treci
mul r5, r4, r0
mov r4, r5
add r3, r3, #1
b poc

treci:
sub r1, r1, r4
mul r4, r0, r2
add r1, r1, r4
mov r0, r1
mov sp, fp
pop {fp, pc}
