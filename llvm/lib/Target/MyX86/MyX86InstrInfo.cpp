#include "MyX86InstrInfo.h"

#include "MyX86Subtarget.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "MyX86GenInstrInfo.inc"

using namespace llvm;

MyX86InstrInfo::MyX86InstrInfo(const MyX86Subtarget &STI)
    : MyX86GenInstrInfo(STI, RegInfo) {}
