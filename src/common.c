#include "common.h"

void outb(u16int port, u8int value) {
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port) {
    u8int ret;
    asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

u16int inw(u16int port) {
    u16int ret;
    asm volatile("inw %1, %0" : "=a" (ret) : "dN" (port));
    return ret;
}

void memset(u8int *ptr, u8int value, u32int num) {
    u32int i = 0;
    for (i = 0; i < num; i++) {
        ptr[i] = value;
    }
}

void memcpy(u8int *dest, const u8int *src, u32int num) {
    u32int i = 0;
    for (i = 0; i < num; i++) {
        dest[i] = src[i];
    }
}
