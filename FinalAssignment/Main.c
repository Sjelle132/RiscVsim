#include <stdio.h>
#include <stdint.h>

#include "fetch.h"
#include "Typedef2.h"
#include "ALU.h"


int main() {

	CPU_t CPU;
	initCPU(&CPU);

	readFile_t myFile;
	const char* inputFilePath = "C:/Users/oscar/Desktop/CA/cae-lab-master/finasgmt/tests/task1/shift2.bin";
	int bool = 0;

	if (fetchData(inputFilePath, &myFile) == 0) {
		for (size_t i = 0; i < myFile.size; ++i) {
			printf("%08x\n", myFile.data[i]);
		}
		//free(myFile.data);
	} else {
		// Error handling
	}

	printf("Initialized registers: \n");
		for(int i=0; i < 32; i++){
			printf("Reg%d %d\n", i , CPU.regs[i]);
		}

	for (int k=0; k <= myFile.size; k++){//myFile.size; k++) {
		printf("After a single instruction: \n");
		ALU(&CPU, myFile.data[CPU.pc >> 2]);
		printf("Initialized registers: \n");
		for(int i=0; i < 32; i++){
			printf("Reg%d %d\n", i , CPU.regs[i]);
		}
		printf("pc is: %d", CPU.pc);
		printf("bool is: %d", bool);
		//CPU.pc += 4;

//		 if ((CPU.pc >> 2) >= myFile.size) {
//
//		            bool = 1;
//
//		        }
	}
	return 0;
}

