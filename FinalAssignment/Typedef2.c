/*
 * Typedef2.c
 *
 *  Created on: 13. nov. 2023
 *      Author: oscar
 */

#include "Typedef2.h"


//Init values
void initCPU (CPU_t* CPU){
	CPU->pc = 0;

	for (int i = 0; i <  32; i++) {
		CPU->regs[i] = 0;
	}
}






