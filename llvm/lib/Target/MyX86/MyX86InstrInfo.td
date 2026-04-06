

class MyX86 : Instruction {
    let Namespace = "MyX86";
}


def RET : MyX86 {
    /*bits<8> Opcode = 0xc3;
    string AsmString = "retq"
    bit isReturn = 1;
    bit isTerminator = 1;
    bit isBarrier = 1;*/
    let AsmString = "retq";
    let OutOperandList = (outs);
    let InOperandList = (ins);
}
