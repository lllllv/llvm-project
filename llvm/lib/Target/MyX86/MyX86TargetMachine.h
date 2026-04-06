//
// Created by Lv on 24-12-29.
//

#ifndef LLVM_MYX86TARGETMACHINE_H
#define LLVM_MYX86TARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"

#include "MyX86GenRegisterInfo.inc"

#include "MyX86Subtarget.h"

namespace llvm {
class MyX86TargetMachine : public CodeGenTargetMachineImpl {
private:
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  std::unique_ptr<MyX86Subtarget> STI;

public:
  MyX86TargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                     StringRef FS, const TargetOptions &Options,
                     std::optional<Reloc::Model> RM,
                     std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                     bool JIT);

  ~MyX86TargetMachine() = default;

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;

  TargetLoweringObjectFile *getObjFileLowering() const override;

  const MyX86Subtarget *getSubtargetImpl(const Function &F) const override;
};
} // namespace llvm

#endif // LLVM_MYX86TARGETMACHINE_H
