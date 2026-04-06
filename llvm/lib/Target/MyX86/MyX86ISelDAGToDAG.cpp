#include "llvm/Pass.h"
#include <cstdio>

#include "MyX86.h"
#include "MyX86ISelDAGToDAG.h"

#define DEBUG_TYPE "myx86-isel"
#define PASS_NAME "X86-64 DAG->DAG Pattern Instruction Selection"

using namespace llvm;

void MyX86DAGToDAGISel::Select(SDNode *N) { printf("SELECT HERE########\n"); }

char MyX86DAGToDAGISelLegacy::ID = 0;

MyX86DAGToDAGISelLegacy::MyX86DAGToDAGISelLegacy(
    MyX86TargetMachine &TargetMachine, CodeGenOptLevel OptLevel)
    : SelectionDAGISelLegacy(
          ID, std::make_unique<MyX86DAGToDAGISel>(TargetMachine, OptLevel)) {}

INITIALIZE_PASS(MyX86DAGToDAGISelLegacy, DEBUG_TYPE, PASS_NAME, false, false)

FunctionPass *llvm::createMyX86ISelDag(MyX86TargetMachine &TM,
                                       CodeGenOptLevel OptLevel) {
  return new MyX86DAGToDAGISelLegacy(TM, OptLevel);
}
