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
	int imm_U = (inst & 0b11111111111111111111000000000000);
	int imm_S = ((inst & 0xfe000000 >> 20)) | ((inst >> 7) & 0x1f);



	int funct3 = (inst >> 12) & 0x7 ;
	int funct7 = (inst >> 25) & 0x7f;


	switch (opcode) {
	case 0x13: //I
		switch (funct3) {
		case 0:
			//addi
			CPU->regs[rd] = CPU->regs[rs1] + imm_I;
			break;
		case 1:
			switch (funct7){
			case 0:
				//slli
				CPU->regs[rd] = CPU->regs[rs1]<< imm_I;
				break;

			default:
				break;
			}
			break;
			case 2:
				//slti
				CPU->regs[rd] = (CPU->regs[rs1] - imm_I) < 0 ? 1:0;
				break;
			case 3:
				//sltiu*
				CPU->regs[rd] = (CPU->regs[rs1] < imm_I) ? 1:0;
				break;

			case 4:
				//xori
				CPU->regs[rd] = CPU->regs[rs1] ^ imm_I;
				break;

			case 5:
				switch (funct7){
				case 0:
					//srli*
					CPU->regs[rd] = CPU->regs[rs1] >>  imm_I ;
					break;
				case 32:
					//srai
					CPU->regs[rd] = (signed int) CPU->regs[rs1] >>  imm_I ;
					break;
				default:
					break;
				}
				break;

				case 6:
					//ori
					CPU->regs[rd] = CPU->regs[rs1] | imm_I;
					break;

				case 7:
					//andi
					CPU->regs[rd] = CPU->regs[rs1] & imm_I;
					break;

		}

		break;

		default:
			printf("du grim");
			break;

		case 55:
			//lui
			CPU->regs[rd] = imm_U;
			break;
		case 0b0110011: //R:
			switch (funct3){
			case 0:
				switch(funct7) {
				case 0b0000000:
					//add
					CPU->regs[rd] = CPU->regs[rs1] + CPU->regs[rs2];
					break;
				case 0b0100000:
					//sub
					CPU->regs[rd] = CPU->regs[rs1] - CPU->regs[rs2];
					break;
				}

				break;
			case 1:
				//sll*
				CPU->regs[rd] = CPU->regs[rs1] << CPU->regs[rs2];
				break;
			case 2:
				//slt
				CPU->regs[rd] = (CPU->regs[rs1] < CPU->regs[rs2]) ? 1:0;
				break;
			case 3:
				//sltu
				CPU->regs[rd] = (CPU->regs[rs1] < CPU->regs[rs2]) ? 1:0;
				break;
			case 4:
				//xor
				CPU->regs[rd] = CPU->regs[rs1] ^ CPU->regs[rs2];
				break;
			case 5:
				switch(funct7){
				case 0b0000000:
					//srl
					CPU->regs[rd] = CPU->regs[rs1] >> CPU->regs[rs2];
					break;
				case 0b0100000:
					//sra*
					CPU->regs[rd] = (signed int) CPU->regs[rs1] >> CPU->regs[rs2];
					break;
				}
				break;
			case 6:
				//or
				CPU->regs[rd] = CPU->regs[rs1] | CPU->regs[rs2];
				break;
			case 7:
				//and
				CPU->regs[rd] = CPU->regs[rs1] & CPU->regs[rs2];
				break;
			}
			break;
	}
	CPU->pc += 4;
}

