SOURCES=boot.o main.o monitor.o common.o isr.o gdt.o gdt_flush.o idt.o idt_flush.o timer.o kheap.o paging.o

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32
LDFLAGS=-Tlink.ld -melf_i386
ASFLAGS=-felf

all: $(SOURCES) link

clean:
	rm *.o kernel

link:
	ld $(LDFLAGS) -o kernel $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<
