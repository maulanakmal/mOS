#include "monitor.h"
#include "gdt.h"
#include "idt.h"

int main(struct multiboot *mboot_ptr){
    init_gdt();
    init_idt();
    monitor_clear();
    monitor_write("Hello, world!\n");
    asm volatile("int $0x3");
    asm volatile("int $0x4");
    return 0xDEADBEAF;
}
