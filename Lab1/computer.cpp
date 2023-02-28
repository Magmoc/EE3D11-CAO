#include "computer.hpp"

Computer::Computer(double i_clockRateGHz, double i_cpiArith, double i_cpiStore, double i_cpiLoad, double i_cpiBranch){
    clockRateGHz = i_clockRateGHz;
    cpiArith = i_cpiArith;
    cpiStore = i_cpiStore;
    cpiLoad = i_cpiLoad;
    cpiBranch = i_cpiBranch;
}

void Computer::printStats(void){
    std::cout << "clockRateGHz = " << clockRateGHz << "\n";
    std::cout << "cpiArith = " << cpiArith << "\n";
    std::cout << "cpiStore = " << cpiStore << "\n";
    std::cout << "cpiLoad = " << cpiLoad << "\n";
    std::cout << "cpiBranch = " << cpiBranch << "\n\n";
}

double Computer::calculateGlobalCPI(void){
    double cpiGlobal = (cpiArith + cpiStore + cpiLoad + cpiBranch) / 4;
    return cpiGlobal;
}

double Computer::calculateExecutionTime(Program programUnderTest){
    double executionTime_ns, executionTime_s;
    int cyclesArith, cyclesStore, cyclesLoad, cyclesBranch, cyclesTotal;

    cyclesArith = cpiArith * programUnderTest.numArith;
    cyclesStore = cpiStore * programUnderTest.numStore;
    cyclesLoad = cpiLoad * programUnderTest.numLoad;
    cyclesBranch = cpiBranch * programUnderTest.numBranch;

    cyclesTotal = cyclesArith + cyclesStore + cyclesLoad + cyclesBranch;

    executionTime_ns = cyclesTotal / clockRateGHz;

    executionTime_s = executionTime_ns / 1e9;

    return executionTime_s;
}

double Computer::calculateMIPS(void){
    double MIPS;

    double cpiGlobal = Computer::calculateGlobalCPI();

    // scaling to get to Million per second
    MIPS = 1e9 * clockRateGHz / (1e6* cpiGlobal);

    std::cout << "MIPS: " << MIPS << std::endl;

    return MIPS;
}

double Computer::calculateMIPS(Program programUnderTest){
    double MIPS, executionTime_s;

    executionTime_s = calculateExecutionTime(programUnderTest);

    // scaling to get million instructions per second
    MIPS = programUnderTest.numTotal / (1e6 * executionTime_s);

    std::cout << "MIPS based on program: " << MIPS << std::endl;

    return MIPS;
}

