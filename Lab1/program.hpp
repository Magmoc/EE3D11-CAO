#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <iostream>

class Program{
    private:
    public:
        Program(int i_numArith, int i_numStore, int i_numLoad, int i_numBranch);
        Program(int i_totalNumInstruction, double i_fracArith, double i_fracStore, double i_fracLoad);
        void printStats(void);
        int numArith, numStore, numLoad, numBranch, numTotal;
};

#endif
