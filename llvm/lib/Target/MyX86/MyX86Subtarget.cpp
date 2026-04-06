#define GET_SUBTARGETINFO_CTOR

#include "MyX86Subtarget.h"

using namespace llvm;

MyX86Subtarget::MyX86Subtarget(const Triple &TT, StringRef &CPU,
                               const StringRef &FS, const TargetMachine &TM)
    : MyX86GenSubtargetInfo(TT, CPU, CPU, FS), TLInfo(TM, *this),
      InstrInfo(*this), FrameLowering(*this) {
  return;
}

const TargetLowering *MyX86Subtarget::getTargetLowering() const {
  return &TLInfo;
}

const TargetRegisterInfo *MyX86Subtarget::getRegisterInfo() const {
  return &InstrInfo.getRegisterInfo();
}

const TargetFrameLowering *MyX86Subtarget::getFrameLowering() const {
  return &FrameLowering;
}
