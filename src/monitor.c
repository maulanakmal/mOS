#include "monitor.h"

u16int *video_memory = (u16int *)0xB8000;
u8int cursor_x = 0;
u8int cursor_y = 0;

static void move_cursor() {
    u16int cursor_location = cursor_y * 80 + cursor_x;
    outb(0x3D4, 14);
    outb(0x3D5, cursor_location >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, cursor_location);
}

static void scroll() {
    u8int attribute_byte = (0 << 4) | (15 & 0x0F);
    u16int blank = 0x20 | (attribute_byte << 8);
    
    if (cursor_y >= 25) {
        int i;
        for (i = 0*80; i< 24*80; i++) {
            video_memory[i] = video_memory[i+80];
        }
        for (i = 24*80; i< 25*80; i++) {
            video_memory[i] = blank;
        }

        cursor_y = 24;
    }
}


void monitor_put(char c) {
    u8int background_color = 0;
    u8int foreground_color= 15;

    u8int attribute_byte = (background_color << 4) | (foreground_color & 0x0F);
    u16int attribute = attribute_byte << 8;
    u16int *location;

    if (c == 0x08 && cursor_x) {
        cursor_x--;
    }
    else if (c == 0x09) {
        cursor_x = (cursor_x+8) & ~(8-1);
    }
    else if (c == '\r') {
        cursor_x = 0;
    }
    else if (c == '\n') {
        cursor_x = 0;
        cursor_y++;
    }
    else if (c >= ' ') {
        location = video_memory + (cursor_y*80 + cursor_x);
        *location = c | attribute;
        cursor_x++;
    }

    if (cursor_x >= 80) {
        cursor_x = 0;
        cursor_y++;
    }
    scroll();
    move_cursor();
}


void monitor_clear() {
    u8int attribute_byte = (0 << 4) | (15 & 0x0F);
    u16int blank = 0x20 | (attribute_byte << 8);

    int i;
    for (i = 0; i < 80*25; i++) {
        video_memory[i] = blank;
    }

    cursor_x = 0;
    cursor_y = 0;
    move_cursor();
}

void monitor_write(char *c) {
    int i = 0;
    while (c[i]) {
        monitor_put(c[i++]);
    }
}

void monitor_write_dec(u32int n) {
    char c[32];
    u8int i = 0;
    while( n > 0 ){
        c[i] = '0' + (n%10);
        n = n / 10;
        i++;
    } 
    while (i >= 0) {
        monitor_put(c[i]);
        i--;
    }
}

void monitor_write_hex(u32int n) {
  int tmp;
  char noZeroes = 1;

  monitor_write("0x");

  int i;
  for (i = 28; i >= 0; i -= 4)
  {
    tmp = (n >> i) & 0xF;
    if (tmp == 0 && noZeroes != 0)
      continue;

    noZeroes = 0;
    if (tmp >= 0xA)
      monitor_put (tmp-0xA+'a' );
    else
      monitor_put( tmp+'0' );
  }
}
