#ifndef LLVM_MYX86MCTARGETDESC_H
#define LLVM_MYX86MCTARGETDESC_H

#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"

#define GET_REGINFO_ENUM
#include "MyX86GenRegisterInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "MyX86GenSubtargetInfo.inc"

#endif
