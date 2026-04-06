#ifndef LLVM_LIB_TARGET_MYX86_MCTARGETDESC_MYX64MCASMINFO_H
#define LLVM_LIB_TARGET_MYX86_MCTARGETDESC_MYX64MCASMINFO_H

#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCAsmInfoELF.h"
#include "llvm/TargetParser/Triple.h"

namespace llvm {


  class MyX86MCAsmInfo : public MCAsmInfo {
    public:
    explicit MyX86MCAsmInfo(const Triple &TT);
  };

} // namespace llvm

#endif
