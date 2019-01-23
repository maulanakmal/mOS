#include "monitor.h"
#include "gdt.h"
#include "idt.h"

int main(struct multiboot *mboot_ptr){
    init_descriptor_tables();
    monitor_clear();
    monitor_write("Hello, world!");
    asm volatile("int $0x3");
    asm volatile("int $0x4");
    return 0xDEADBEAF;
}
