//
// Created by Lv on 24-12-29.
//
#include "MyX86TargetInfo.h"

#include "llvm/MC/TargetRegistry.h"
using namespace llvm;

namespace llvm {

Target &getMyX86Target() {
  static Target MyX86Target;
  return MyX86Target;
}

} // end namespace llvm

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMyX86TargetInfo() {
  RegisterTarget<Triple::MyX86, false> X(getMyX86Target(), "MyX86",
                                         "64-bit MyX86", "MyX86-64");
}