#ifndef COMPUTER_HPP
#define COMPUTER_HPP

#include <iostream>
#include "program.hpp"

class Computer{
    private:
        double clockRateGHz;
        double cpiArith;
        double cpiStore;
        double cpiLoad;
        double cpiBranch;
    public:
        Computer(double i_clockRateGHz, double i_cpiArith, double i_cpiStore, double i_cpiLoad, double i_cpiBranch);
        void printStats(void);
        double calculateGlobalCPI(void);
        double calculateExecutionTime(Program programUnderTest);
        double calculateMIPS(void);
        double calculateMIPS(Program);
};

#endif
