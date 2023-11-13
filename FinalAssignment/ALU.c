/*
 * ALU.c
 *
 *  Created on: 13. nov. 2023
 *      Author: oscar
 */
#include "Typedef2.h"
#include "ALU.h"

void ALU(CPU_t* CPU, int testvalue){

	int inst = testvalue;

	int opcode = inst & 0x7f;
	int rd = (inst >> 7) & 0x01f;

	int rs1 = (inst >> 15) & 0x01f;
	int rs2 = (inst >> 20) & 0x01f;

	int imm_I = (inst >> 20);
	int imm_B = ((inst & 0x80000000) >> 19) | ((inst & 0x80) << 4) | ((inst >> 20) & 0x7e0) | ((inst >> 7 ) & 0x1e) ;
	int imm_J = ((inst & 0x80000000) >> 11) | ((inst & 0xff000)) | ((inst >> 9) & 0x800) | ((inst >> 20 ) & 0x7f3) ;
	int imm_U = (inst & 0xfffff999);
	int imm_S = ((inst & 0xfe000000 >> 20)) | ((inst >> 7) & 0x1f);

	int funct3 = (inst >> 12) & 0x7 ;
	int funct7 = (inst >> 25) & 0x7f;


	switch (opcode) {
		case 0x13: //Opcode
			switch (funct3) {
				case 0:
					CPU->regs[rd] = CPU->regs[rs1] + imm_I;
					break;
				case 1:
					switch (funct7){
						case 0:
							//slli
							break;
						default:
							break;
						}
					break;
				case 2:
					//slti
					break;
				case 3:
					//sltiu
					break;

				case 4:
					//xori
					break;

				case 5:
					switch (funct7){
						case 0:
							//srli
							break;
						case 32:
							//srai
							break;
						default:
							break;
					}
					break;

				case 6:
					//ori
					break;

				case 7:
					//andi
					break;

		}

		break;

		default:
			printf("du grim");
			break;
	}
}

