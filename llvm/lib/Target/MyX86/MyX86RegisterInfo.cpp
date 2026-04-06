#include "MyX86RegisterInfo.h"
#include "MyX86FrameLowering.h"

#define GET_REGINFO_TARGET_DESC
#include "MyX86GenRegisterInfo.inc"

using namespace llvm;

MyX86RegisterInfo::MyX86RegisterInfo()
    : MyX86GenRegisterInfo(MyX86::RIP, 0, 0, MyX86::RIP, 0) {}

bool MyX86RegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator MI,
                                            int SPAdj, unsigned FIOperandNum,
                                            RegScavenger *RS) const {
  return false;
}

const MCPhysReg *
MyX86RegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  return CSR_64_SaveList;
}

BitVector MyX86RegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());
  Reserved.set(MyX86::RIP);
  Reserved.set(MyX86::RSP);
  Reserved.set(MyX86::RBP);

  return Reserved;
}

Register MyX86RegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return MyX86::RBP;
}

Register MyX86RegisterInfo::getStackRegister(const MachineFunction &MF) const {
  return MyX86::RSP;
}
