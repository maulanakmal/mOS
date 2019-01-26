#include "monitor.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"
#include "paging.h"

int main(struct multiboot *mboot_ptr){
    monitor_clear();
    init_gdt();
    init_idt();
    init_paging();
    monitor_write("Hello, paging world!\n");

    u32int *ptr = (u32int*)0xA0000000;
    u32int do_page_fault = *ptr;

    return 0xDEADBEAF;
}
