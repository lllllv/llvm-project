
#include "MyX86MCAsmInfo.h"

using namespace llvm;

MyX86MCAsmInfo::MyX86MCAsmInfo(const Triple &TT) {

  CommentString = "#";
  ExceptionsType = ExceptionHandling::DwarfCFI;
}
