#include "program.hpp"

Program::Program(int i_numArith, int i_numStore, int i_numLoad, int i_numBranch){
    numArith = i_numArith;
    numStore = i_numStore;
    numLoad = i_numLoad;
    numBranch = i_numBranch;
    numTotal = numArith + numStore + numLoad + numBranch;
}

Program::Program(int i_totalNumInstruction, double i_fracArith, double i_fracStore, double i_fracLoad){
    numTotal = i_totalNumInstruction;
    numArith = (int) (i_totalNumInstruction * i_fracArith);
    numStore = (int) (i_totalNumInstruction * i_fracStore);
    numLoad = (int) (i_totalNumInstruction * i_fracLoad);
    numBranch = i_totalNumInstruction - numArith - numStore - numLoad;
}


void Program::printStats(void){
    std::cout << "numArith = " << numArith << "\n";
    std::cout << "numStore = " << numStore << "\n";
    std::cout << "numLoad = " << numLoad << "\n";
    std::cout << "numBranch = " << numBranch << "\n\n";
}
