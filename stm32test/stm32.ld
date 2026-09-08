MEMORY {
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
    RAM (rwx)  : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS {
    .text : {
        *(.isr_vector) /* Đặt bảng vector lên đầu Flash */
        *(.text)       /* Chứa code chương trình */
    } > FLASH
}
