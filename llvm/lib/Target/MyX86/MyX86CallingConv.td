


def RetCC_MyX86 : CallingConv<[
    CCIfType<[i64], CCAssignToReg<[RAX]>>,
]>;

def CC_MyX86 : CallingConv<[
    CCIfType<[i64], CCAssignToStack<4, 4>>,
]>;

def CSR_64 : CalleeSavedRegs<(add RBX, R12, R13, R14, R15, RBP)>;
