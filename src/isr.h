#ifndef ISR_H
#define ISR_H

#include "common.h"

typedef struct registers {
    u32int ds;
    u32int edi, esi, ebp, esp, ebx, ecx, eax;
    u32int int_no, err_code;
    u32int eip, cs, eflags, useresp, ss;
} registers_t;

void isr_handler(registers_t regs);

void isr_handler(registers_t regs);

typedef void (*isr_t)(registers_t);
void register_interrupt_handler(u8int n, isr_t handler);

#endif
