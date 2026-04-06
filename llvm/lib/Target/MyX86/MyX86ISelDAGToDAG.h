
#ifndef LLVM_LIB_TARGET_MYX86_MYX86ISELDAGTODAG_H
#define LLVM_LIB_TARGET_MYX86_MYX86ISELDAGTODAG_H

#include "llvm/CodeGen/SelectionDAGISel.h"

#include "MyX86TargetMachine.h"

namespace llvm {

class MyX86DAGToDAGISel : public SelectionDAGISel {
public:
  explicit MyX86DAGToDAGISel(MyX86TargetMachine &TargetMachine,
                             CodeGenOptLevel OptLevel)
      : SelectionDAGISel(TargetMachine, OptLevel) {}
  void Select(SDNode *N) override;
};

class MyX86DAGToDAGISelLegacy : public SelectionDAGISelLegacy {
public:
  static char ID;
  explicit MyX86DAGToDAGISelLegacy(MyX86TargetMachine &TargetMachine,
                                   CodeGenOptLevel OptLevel);
};

} // namespace llvm

#endif