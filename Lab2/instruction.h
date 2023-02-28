    #ifndef _INSTRUCTION_H_
    #define _INSTRUCTION_H_

    #include <iostream>
    #include "registers.h"

    using namespace std;

    class Instruction{
        private:
        protected:
            int args[3];
        public:
            Instruction(int i_reg0, int i_reg1, int i_reg2);
            virtual ~Instruction(){};

            virtual void disassemble() = 0;
            virtual int execute (Registers *) = 0;

    };

    class AddInstruction : public Instruction {
        private:
        protected:
        public:
            AddInstruction(int i_reg0, int i_reg1, int i_reg2) : Instruction(i_reg0, i_reg1, i_reg2){}
            void disassemble();
            int execute (Registers *);
    };

    class SubInstruction : public Instruction {
        private:
        protected:
        public:
            SubInstruction(int i_reg0, int i_reg1, int i_reg2) : Instruction(i_reg0, i_reg1, i_reg2){}
            void disassemble();
            int execute (Registers *);
    };

    class OriInstruction : public Instruction {
        private:
        protected:
        public:
            OriInstruction(int i_reg0, int i_reg1, int i_reg2) : Instruction(i_reg0, i_reg1, i_reg2){}
            void disassemble();
            int execute (Registers *);
    };

    class BrneInstruction : public Instruction {
        private:
        protected:
        public:
            BrneInstruction(int i_reg0, int i_reg1, int i_reg2) : Instruction(i_reg0, i_reg1, i_reg2){}
            void disassemble();
            int execute (Registers *);
    };

    #endif /* _INSTRUCTION_H_ */
