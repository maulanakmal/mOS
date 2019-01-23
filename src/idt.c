#include "common.h"
#include "idt.h"


extern void idt_flush(u32int);

static void init_idt();
static void idt_set_gate(u8int, u32int, u16int, u8int);

idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;


static void init_idt() {
    idt_ptr.limit = sizeof(idt_entry_t)*256 - 1;
    idt_ptr.base = (u32int)&idt_entries;

    memset(&idt_entries, 0, sizeof(idt_entry_t)*256);

    idt_set_gate(0, (u32int)isr0, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr1, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr2, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr3, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr4, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr5, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr6, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr7, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr8, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr9, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr10, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr11, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr12, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr13, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr14, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr15, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr16, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr17, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr18, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr19, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr20, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr21, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr22, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr23, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr24, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr25, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr26, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr27, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr28, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr29, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr30, 0x08, 0x8E);
    idt_set_gate(0, (u32int)isr31, 0x08, 0x8E);

    idt_flush((u32int)&idt_ptr);
}

static void idt_set_gate(u8int num, u32int base, u16int sel, u8int flags) {
    idt_entries[num].base_low = base & 0xFFFF;
    idt_entries[num].base_high = (base >> 16) & 0xFFFF;
    idt_entries[num].sel = sel;
    idt_entries[num].always0 = 0;
    idt_entries[num].flags = flags /* | 0x60 */; // for user mode
}
