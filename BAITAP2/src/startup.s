.syntax unified
.cpu cortex-m3
.thumb

.global Reset_Handler
.global _estack


/* =========================
   Vector Table
   ========================= */

.section .isr_vector, "a", %progbits

.word _estack
.word Reset_Handler

.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler
.word Default_Handler


/* =========================
   Reset Handler
   ========================= */

.section .text.Reset_Handler
.type Reset_Handler, %function

Reset_Handler:

    bl main

Loop:
    b Loop


/* =========================
   Default Handler
   ========================= */

.section .text.Default_Handler
.type Default_Handler, %function

Default_Handler:

    b .


