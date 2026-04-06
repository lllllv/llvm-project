#ifndef LLVM_MYX86INSTRINFO_H
#define LLVM_MYX86INSTRINFO_H
#include "llvm/CodeGen/TargetInstrInfo.h"

#include "MyX86RegisterInfo.h"

#define GET_INSTRINFO_HEADER
#include "MyX86GenInstrInfo.inc"

namespace llvm {
class MyX86Subtarget;

class MyX86InstrInfo : public MyX86GenInstrInfo {
  const MyX86RegisterInfo RegInfo;

public:
  explicit MyX86InstrInfo(const MyX86Subtarget &STI);
};
} // namespace llvm

#endif
