//
// Created by Lv on 24-12-29.
//

#include "MyX86TargetMachine.h"
#include "MyX86RegisterInfo.h"
#include "TargetInfo/MyX86TargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"
#include <memory>

#include "MyX86.h"
#include "MyX86GenRegisterInfo.inc"

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMyX86Target() {
  // Register the target.
  RegisterTargetMachine<MyX86TargetMachine> X(getMyX86Target());
  auto *PR = PassRegistry::getPassRegistry();
  initializeMyX86DAGToDAGISelLegacyPass(*PR);
}

class MyX86PassConfig : public TargetPassConfig {
public:
  MyX86PassConfig(MyX86TargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  MyX86TargetMachine &getMyX86TargetMachine() const {
    return getTM<MyX86TargetMachine>();
  }

  bool addInstSelector() override;
};

bool MyX86PassConfig::addInstSelector() {
  addPass(createMyX86ISelDag(getMyX86TargetMachine(), getOptLevel()));

  return false;
}

MyX86TargetMachine::MyX86TargetMachine(const Target &T, const Triple &TT,
                                       StringRef CPU, StringRef FS,
                                       const TargetOptions &Options,
                                       std::optional<Reloc::Model> RM,
                                       std::optional<CodeModel::Model> CM,
                                       CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "E-p:64:64-i32:32", TT, CPU, FS, Options,
                               Reloc::Static, CodeModel::Small, OL) {
  initAsmInfo();

  TLOF = std::make_unique<TargetLoweringObjectFileELF>();
  STI = std::make_unique<MyX86Subtarget>(TT, CPU, FS, *this);
}

TargetPassConfig *MyX86TargetMachine::createPassConfig(PassManagerBase &PM) {
  return new MyX86PassConfig(*this, PM);
}

TargetLoweringObjectFile *MyX86TargetMachine::getObjFileLowering() const {
  return TLOF.get();
}

const MyX86Subtarget *
MyX86TargetMachine::getSubtargetImpl(const Function &F) const {
  return STI.get();
}
