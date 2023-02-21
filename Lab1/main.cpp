#include <iostream>
#include "computer.hpp"
#include "program.hpp"

void assignment1_1(void);
void assignment1_2(void);
void assignment1_3(void);
void testComputerSingleProgram(Computer &computerUnderTest, Program programUnderTest);
void testComputerAllPrograms(Computer &computerUnderTest, Program programA, Program programB, Program programC);

void assignment1_1(void){
    Computer iMac9000(1.0, 2.0, 3.0, 4., 5.0);
    iMac9000.printStats();
    std::cout << iMac9000.calculateGlobalCPI() << std::endl;

    Computer iMac9001(2.0, 500, 3.9, 5.0, 60);
    iMac9001.printStats();
    std::cout << iMac9001.calculateGlobalCPI() << std::endl;
}

void assignment1_2(void){
    Program program1(100, 200, 300, 4);
    program1.printStats();

    Program program2(1000, 0.3, 0.4, 0.1);
    program2.printStats();
}

void testComputerSingleProgram(Computer &computerUnderTest, Program programUnderTest){
    computerUnderTest.calculateExecutionTime(programUnderTest);
    computerUnderTest.calculateMIPS(programUnderTest);
}

void testComputerAllPrograms(Computer &computerUnderTest, Program programA, Program programB, Program programC){
    double executionTime;

    computerUnderTest.printStats();
    computerUnderTest.calculateMIPS();
    std::cout << "Program A: " << std::endl;
    testComputerSingleProgram(computerUnderTest, programA);
    std::cout << "Program B: " << std::endl;
    testComputerSingleProgram(computerUnderTest, programB);
    std::cout << "Program C: " << std::endl;
    testComputerSingleProgram(computerUnderTest, programC);
    std::cout << std::endl;
}

void assignment1_3(void){
    Computer computer1(1, 2, 2, 3, 4);
    Computer computer2(1.2, 2, 3, 4, 3);
    Computer computer3(2, 2, 2, 4, 6);

    Program programA(2000, 100, 100, 50);
    Program programB(2000, 0.1, 0.4, 0.25);
    Program programC(500, 100, 2000, 200);

    std::cout << "Computer 1: \n";
    testComputerAllPrograms(computer1, programA, programB, programC);
    std::cout << "Computer 2: \n";
    testComputerAllPrograms(computer2, programA, programB, programC);
    std::cout << "Computer 3: \n";
    testComputerAllPrograms(computer3, programA, programB, programC);

}

int main()
{
    //assignment1_1();
    //assignment1_2();
    assignment1_3();

    return 0;
}
