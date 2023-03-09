#include <iostream>
#include "instruction.h"

using namespace std;

Instruction::Instruction(int i_reg0, int i_reg1, int i_reg2){
    args[0] = i_reg0;
    args[1] = i_reg1;
    args[2] = i_reg2;
}

void AddInstruction::disassemble(){
    std::cout << "add $" << args[0] << ", $" << args[1] << ", $" << args[2] << std::endl;
}

int AddInstruction::execute(Registers * inputRegisters){
    int registerValueA = inputRegisters->getRegister(args[1]);
    int registerValueB = inputRegisters->getRegister(args[2]);

    int result = registerValueA + registerValueB;
    inputRegisters->setRegister(args[0], result);
    inputRegisters->incrementPC();

    return inputRegisters->getPC();
}


void SubInstruction::disassemble(){
    std::cout << "sub $" << args[0] << ", $" << args[1] << ", $" << args[2] << std::endl;
}

int SubInstruction::execute(Registers * inputRegisters){
    int registerValueA = inputRegisters->getRegister(args[1]);
    int registerValueB = inputRegisters->getRegister(args[2]);

    int result = registerValueA - registerValueB;
    inputRegisters->setRegister(args[0], result);
    inputRegisters->incrementPC();

    return inputRegisters->getPC();
}


void OriInstruction::disassemble(){
    std::cout << "ori $" << args[0] << ", $" << args[1] << ", " << args[2] << std::endl;
}

int OriInstruction::execute(Registers * inputRegisters){
    int registerValueA = inputRegisters->getRegister(args[1]);

    int result = registerValueA | args[2];
    inputRegisters->setRegister(args[0], result);
    inputRegisters->incrementPC();

    return inputRegisters->getPC();
}


void BrneInstruction::disassemble(){
    std::cout << "brne $" << args[0] << ", $" << args[1] << ", " << args[2] << std::endl;
}

int BrneInstruction::execute(Registers * inputRegisters){
    int registerValueA = inputRegisters->getRegister(args[0]);
    int registerValueB = inputRegisters->getRegister(args[1]);

    if (registerValueA != registerValueB){
        int currentPC = inputRegisters->getPC();
        inputRegisters->setPC(currentPC + 1 + args[2]);
    }
    else{
        inputRegisters->incrementPC();
    }

    return inputRegisters->getPC();
}
