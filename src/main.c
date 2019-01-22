#include "monitor.h"

int main(struct multiboot *mboot_ptr){
    monitor_clear();
    monitor_write("Hello, world");
    asm volatile("int $0x3");
    asm volatile("int $0x4");
    return 0xDEADBABA;
}
