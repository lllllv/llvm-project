
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCRegister.h"
#include "llvm/Support/raw_ostream.h"

#include "MyX86InstPrinter.h"

using namespace llvm;

#include "MyX64GenAsmWriter.inc"

void MyX86InstPrinter::printInst(const MCInst *MI, uint64_t Address,
                                 StringRef Annot, const MCSubtargetInfo &STI,
                                 raw_ostream &OS) {}

void MyX86InstPrinter::printRegName(raw_ostream &OS, MCRegister Reg) {}
