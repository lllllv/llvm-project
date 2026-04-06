#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"

#define GET_SUBTARGETINFO_HEADER
#include "MyX86GenSubtargetInfo.inc"

#include "MyX86FrameLowering.h"
#include "MyX86ISelLowering.h"
#include "MyX86InstrInfo.h"

namespace llvm {
class MyX86Subtarget : public MyX86GenSubtargetInfo {

  MyX86TargetLowering TLInfo;
  MyX86InstrInfo InstrInfo;
  MyX86FrameLowering FrameLowering;

public:
  MyX86Subtarget(const Triple &TT, StringRef &CPU, const StringRef &FS,
                 const TargetMachine &TM);

  const TargetLowering *getTargetLowering() const override;
  const TargetRegisterInfo *getRegisterInfo() const override;
  const TargetFrameLowering *getFrameLowering() const override;
};
} // namespace llvm
