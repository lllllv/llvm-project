#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/TargetFrameLowering.h"
#include "llvm/Support/Alignment.h"

namespace llvm {
class MyX86Subtarget;

class MyX86FrameLowering : public TargetFrameLowering {
public:
  explicit MyX86FrameLowering(const MyX86Subtarget &STI)
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(16), 0) {
  }

  void emitPrologue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {};
  void emitEpilogue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {};

protected:
  bool hasFPImpl(const MachineFunction &MF) const override { return true; };
};
} // namespace llvm
