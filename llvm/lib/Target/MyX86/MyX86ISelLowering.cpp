#include "MyX86ISelLowering.h"
#include "MyX86Subtarget.h"

using namespace llvm;

MyX86TargetLowering::MyX86TargetLowering(const TargetMachine &TM,
                                         const MyX86Subtarget &STI)
    : TargetLowering(TM, STI), Subtarget(STI) {}