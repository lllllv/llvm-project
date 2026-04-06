//
// Created by Lv on 25-9-14.
//

#ifndef LLVM_MYX86REGISTERINFO_H
#define LLVM_MYX86REGISTERINFO_H

#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/TargetRegisterInfo.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"

#include "MCTargetDesc/MyX86MCTargetDesc.h"

#define GET_REGINFO_HEADER
#include "MyX86GenRegisterInfo.inc"

using namespace llvm;

namespace llvm {

class MyX86RegisterInfo : public MyX86GenRegisterInfo {
public:
  MyX86RegisterInfo();

  const MCPhysReg *getCalleeSavedRegs(const MachineFunction *MF) const override;

  BitVector getReservedRegs(const MachineFunction &MF) const override;

  bool eliminateFrameIndex(MachineBasicBlock::iterator MI, int SPAdj,
                           unsigned FIOperandNum,
                           RegScavenger *RS = nullptr) const override;

  Register getFrameRegister(const MachineFunction &MF) const override;

  Register getStackRegister(const MachineFunction &MF) const;
};

} // namespace llvm

#endif // LLVM_MYX86REGISTERINFO_H
