include "llvm/Target/Target.td"
include "MyX86RegisterInfo.td"
include "MyX86InstrInfo.td"
include "MyX86CallingConv.td"

defm : RemapAllTargetPseudoPointerOperands<GPR64>;

def : ProcessorModel<"MyX86", NoSchedModel, []>;
def MyX86InstrInfo : InstrInfo;


def MyX86AsmWriter : AsmWriter;

def MyX86 : Target {
    let InstructionSet = MyX86InstrInfo;

    let AssemblyParsers = [];
    let AssemblyWriters = [MyX86AsmWriter];

    let AllowRegisterRenaming = 0;
}



def FeatureGP64Bit : SubtargetFeature<"gp64", "IsGP64bit", "true",
                                "General Purpose Registers are 64-bit wide">;