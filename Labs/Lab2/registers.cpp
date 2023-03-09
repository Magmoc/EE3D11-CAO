#include <iostream>
#include "registers.h"

using namespace std;

Registers::Registers (){
    PC = 0;

    for (int i = 0; i < 32; i++){
        registerArray[i] = 0;
    }
}

void Registers::setRegister(int regNum, int value){
    if (regNum < 0 || regNum > 31){
        throw std::invalid_argument("regNum not between 0 and 31");
    }

    registerArray[regNum] = value;
}

int Registers::getRegister(int regNum){
    if (regNum < 0 || regNum > 31){
        throw std::invalid_argument("regNum not between 0 and 31");
    }

    if (regNum == 0){
        return 0; // register 0 is hardwired 0
    }
    else{
        return registerArray[regNum];
    }
}

void Registers::setPC(int value){
    if (value < 0){
        throw std::invalid_argument("PC cannot be negative");
    }

    PC = value;
}

int Registers::getPC(){
    return PC;
}

void Registers::incrementPC(){
    PC++;
}

void Registers::print(){
    std::cout << "Program Counter: " << PC << endl;

    std::cout << "Register contents:" << std::endl;

    for (int i = 0; i < 32; i++){
        std::cout << "Register[" << i << "] : " << getRegister(i) << std::endl;
    }
}

void testRegisters(){
    Registers registersA;

    registersA.print();

    registersA.setPC(5);
    registersA.setRegister(4, 20);
    registersA.setRegister(0, 400);
//    registersA.setRegister(-5, 400);
//    registersA.setRegister(34, 400);

    registersA.print();
}

