#ifndef _REGISTERS_H_
#define _REGISTERS_H_

class Registers{
    private:
        int PC;
        int registerArray[32];
    public:
        Registers();
        void setRegister(int regNum, int value);
        int getRegister(int regNum);
        void setPC(int value);
        int getPC();
        void incrementPC();
        void print();
};

void testRegisters();

#endif	/* _REGISTERS_H_ */
