/*
 * Typedef2.h
 *
 *  Created on: 13. nov. 2023
 *      Author: oscar
 */

#ifndef TYPEDEF2_H_
#define TYPEDEF2_H_
#define MEM_SIZE 1024*1024*1 //1 MiB, kan ændres til flere ved at ændre 1.

#include <stdint.h>

typedef struct {
	uint32_t pc;
	uint32_t regs[32];
	uint8_t mem[MEM_SIZE];
} CPU_t;

#endif /* TYPEDEF2_H_ */
