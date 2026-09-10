ENTRY(Reset_Handler)

_estack = ORIGIN(RAM) + LENGTH(RAM);

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 64K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}


SECTIONS
{
    /* Code + vector table */

    .text :
    {
        . = ALIGN(4);

        KEEP(*(.isr_vector))

        *(.text)
        *(.text*)

        *(.rodata)
        *(.rodata*)

        . = ALIGN(4);

    } > FLASH


    /* Data */

    .data :
    {
        . = ALIGN(4);

        *(.data)
        *(.data*)

        . = ALIGN(4);

    } > RAM AT > FLASH


    /* BSS */

    .bss :
    {
        . = ALIGN(4);

        *(.bss)
        *(.bss*)

        *(COMMON)

        . = ALIGN(4);

    } > RAM
}
