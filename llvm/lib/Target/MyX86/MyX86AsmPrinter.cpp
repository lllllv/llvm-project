#include "TargetInfo/MyX86TargetInfo.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;
class MyX86AsmPrinter : public AsmPrinter {
public:
  explicit MyX86AsmPrinter(TargetMachine &TM,
                           std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)) {}

  StringRef getPassName() const override { return "MyX86 Assembly Printer"; }

  void emitInstruction(const MachineInstr *MI) override {
    MCInst TmpInst;
    TmpInst.setOpcode(MI->getOpcode());

    for (const auto MO : MI->operands()) {
      if (MO.isReg()) {
        TmpInst.addOperand(MCOperand::createReg(MO.getReg()));
      } else if (MO.isImm()) {
        TmpInst.addOperand(MCOperand::createImm(MO.getImm()));
      } else {
        MO.dump();
        llvm_unreachable("unhandled machine operand type");
      }
    }

    EmitToStreamer(*OutStreamer, TmpInst);
  }
};

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeMyX86AsmPrinter() {
  RegisterAsmPrinter<MyX86AsmPrinter> X(getMyX86Target());
}
