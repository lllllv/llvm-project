#ifndef LLVM_MYX86TARGELOWERING_H
#define LLVM_MYX86TARGELOWERING_H

#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class MyX86Subtarget;

class MyX86TargetLowering : public TargetLowering {
  const MyX86Subtarget &Subtarget;

public:
  explicit MyX86TargetLowering(const TargetMachine &TM,
                               const MyX86Subtarget &STI);
};

} // namespace llvm

#endif