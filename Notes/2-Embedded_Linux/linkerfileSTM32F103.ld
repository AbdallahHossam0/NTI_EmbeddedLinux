_stack_start = ORIGIN(RAM) + LENGTH(RAM)

MEMORY{
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 64K
    /* 
    rx means that:
    r = means this area is a read area, code and data in this area could be read
    x = means this area is executable, code stored in this area could be executed
    */
    RAM(rw) : ORIGIN = 0x20000000, LENGTH = 20K
    /*
    no code in RAM so we don't need the x 
    w = means this area is writable, data can be written here
    */
}

SECTIONS{
    .isr_vector :
    {
        . = ALIGN(4);
        *(.isr_vector)
        *(.isr_vector*)
        . = ALIGN(4);
    } > FLASH
    
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        . = ALIGN(4);
    } > FLASH

    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    // to get the load address of the .data section in flash
    _s_data_FLASH = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _s_data = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _e_data = .;
    } > RAM AT> FLASH
    // means this section is loaded in RAM and they are "AT" FLASH

    .bss :
    {
        . = ALIGN(4);
        _s_bss = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        _e_bss = .;
    } > RAM

}