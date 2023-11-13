#include <stdio.h>
#include <stdint.h>

#include "fetch.h"
#include "Typedef2.h"
#include "ALU.h"


int main() {

	CPU_t CPU;
	initCPU(&CPU);

	int testvalue = 0x00200093;

	printf("Initialized registers: \n");
	for(int i=0; i < 32; i++){
		printf("Reg%d %d\n", i , CPU.regs[i]);
	}


	printf("After a single instruction: \n");
	ALU(&CPU, testvalue);
	printf("Initialized registers: \n");
		for(int i=0; i < 32; i++){
			printf("Reg%d %d\n", i , CPU.regs[i]);
		}
	printf("pc is: %d", CPU.pc);
}


//int main() {
//    readFile_t myFile;
//    const char* inputFilePath = "C:/Users/oscar/Desktop/CA/cae-lab-master/finasgmt/tests/task1/addlarge.bin";
//
//    if (fetchData(inputFilePath, &myFile) == 0) {
//        // Successfully fetched the data
//
//        // Access myFile.data and myFile.size here
//        for (size_t i = 0; i < myFile.size; ++i) {
//            printf("%08x\n", myFile.data[i]);
//            // You can store the values in your desired array in the main function
//            // For example, if you have an array in the main function: uint32_t myArray[MAX_SIZE];
//            // myArray[i] = myFile.data[i];
//        }
//
//        // Don't forget to free the allocated memory when you're done with it
//        free(myFile.data);
//    } else {
//        // Error handling
//    }
//
//    return 0;
//}
