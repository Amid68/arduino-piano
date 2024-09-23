#ifndef __SERIAL_H__
#define __SERIAL_H__

void serial_init(unsigned long baudrate);
void serial_transmit(char data);
void serial_print(const char * str);
void serial_println(const char * str);
void serial_print_int(int value);

#endif
