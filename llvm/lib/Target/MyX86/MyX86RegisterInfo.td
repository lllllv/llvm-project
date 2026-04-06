

class MyX86Reg<string n, bits<16> Enc> : Register<n> {
  let Namespace = "MyX86";
  let HWEncoding = Enc;
}



def RAX : MyX86Reg<"rax", 0>;
def RDX : MyX86Reg<"rdx", 2>;
def RCX : MyX86Reg<"rcx", 1>;
def RBX : MyX86Reg<"rbx", 3>;
def RSI : MyX86Reg<"rsi", 6>;
def RDI : MyX86Reg<"rdi", 7>;
def RBP : MyX86Reg<"rbp", 5>;
def RSP : MyX86Reg<"rsp", 4>;

def R8 : MyX86Reg<"r8", 8>;
def R9 : MyX86Reg<"r9", 9>;
def R10 : MyX86Reg<"r10", 10>;
def R11 : MyX86Reg<"r11", 11>;
def R12 : MyX86Reg<"r12", 12>;
def R13 : MyX86Reg<"r13", 13>;
def R14 : MyX86Reg<"r14", 14>;
def R15 : MyX86Reg<"r15", 15>;

def RIP : MyX86Reg<"rip", 0>;



class GPR64Class<list<ValueType> regTypes> : RegisterClass<"MyX86", regTypes, 64,
                         (add RAX, RCX, RDX, RSI, RDI, RBX, RBP, RSP)>;

def GPR64 : GPR64Class<[i64]>;
