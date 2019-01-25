#include "monitor.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"

int main(struct multiboot *mboot_ptr){
    monitor_clear();
    init_gdt();
    init_idt();
    init_timer(50);
    monitor_write("Hello, world!\n");
    asm volatile("int $0x3");
    asm volatile("int $0x4");
    asm volatile("sti");
    return 0xDEADBEAF;
}
