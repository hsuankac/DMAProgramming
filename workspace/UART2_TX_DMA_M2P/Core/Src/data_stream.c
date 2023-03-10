/*
 * data_stream.c
 *
 *  Created on: Jan 9, 2023
 *      Author: hsuankai.chang
 */

#include <stdint.h>

uint8_t data_stream[] = "Data moving in and out of the data bus is bi-directional, since the processor reads and writes data, however, the others are uni-directional, since the processor always determines when and what it will read from or write to. The address bus carries addressing signals from the processor to memory, I/O (or peripherals), and other addressable devices around the processor. "
		"Control signals move out of the processor, but not in to it.";

uint32_t data_len = sizeof(data_stream);
