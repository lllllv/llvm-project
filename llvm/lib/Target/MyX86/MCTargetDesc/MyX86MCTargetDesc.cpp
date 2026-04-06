//
// Created by Lv on 24-12-29.
//
#include "MyX86InstPrinter.h"
#include "MyX86MCAsmInfo.h"
#include "TargetInfo/MyX86TargetInfo.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInstPrinter.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"

#define GET_REGINFO_MC_DESC
#include "MyX86MCTargetDesc.h"

#define GET_INSTRINFO_MC_DESC
#include "MyX86GenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "MyX86GenSubtargetInfo.inc"

using namespace llvm;

static MCAsmInfo *createMyX86MCAsmInfo(const MCRegisterInfo &MRI,
                                       const Triple &TT,
                                       const MCTargetOptions &Options) {
  return new MyX86MCAsmInfo(TT);
}

static MCRegisterInfo *createMyX86MCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitMyX86MCRegisterInfo(X, MyX86::RIP);
  return X;
}

static MCInstrInfo *createMyX86MCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitMyX86MCInstrInfo(X);
  return X;
}

static MCSubtargetInfo *
createMyX86MCSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS) {
  return createMyX86MCSubtargetInfoImpl(TT, CPU, /*TuneCPU*/ CPU, FS);
}

static MCInstPrinter *createMyX86MCInstPrinter(const Triple &T,
                                               unsigned SyntaxVariant,
                                               const MCAsmInfo &MAI,
                                               const MCInstrInfo &MII,
                                               const MCRegisterInfo &MRI) {
  return new MyX86InstPrinter(MAI, MII, MRI);
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMyX86TargetMC() {
  auto &T = getMyX86Target();
  TargetRegistry::RegisterMCAsmInfo(T, createMyX86MCAsmInfo);
  TargetRegistry::RegisterMCRegInfo(T, createMyX86MCRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(T, createMyX86MCInstrInfo);
  TargetRegistry::RegisterMCSubtargetInfo(T, createMyX86MCSubtargetInfo);
  TargetRegistry::RegisterMCInstPrinter(T, createMyX86MCInstPrinter);
}
