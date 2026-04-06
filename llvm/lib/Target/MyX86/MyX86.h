#include "llvm/Support/CodeGen.h"

namespace llvm {
  class MyX86TargetMachine;
  class FunctionPass;

  class PassRegistry;

  FunctionPass *createMyX86ISelDag(MyX86TargetMachine &TM, CodeGenOptLevel OptLevel);
  void initializeMyX86DAGToDAGISelLegacyPass(PassRegistry &);

} // namespace llvm
