#include "common.h"

typedef struct registers {
    u32int ds;
    u32int edi, esi, ebp, esp, ebx, ecx, eax;
    u32int int_no, err_code;
    u32int eip, cs, eflags, useresp, ss;
} registers_t;
