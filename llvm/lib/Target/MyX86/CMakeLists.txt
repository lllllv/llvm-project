add_llvm_component_group(MyX86)

set(LLVM_TARGET_DEFINITIONS MyX86.td)

tablegen(LLVM MyX86GenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MyX86GenCallingConv.inc -gen-callingconv)
tablegen(LLVM MyX86GenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM MyX86GenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MyX64GenAsmWriter.inc -gen-asm-writer)

add_public_tablegen_target(MyX86CommonTableGen)

set(sources
        MyX86TargetMachine.cpp
        MyX86RegisterInfo.cpp
        MyX86Subtarget.cpp
        MyX86ISelDAGToDAG.cpp
        MyX86AsmPrinter.cpp
        MyX86ISelLowering.cpp
        MyX86InstrInfo.cpp
)

add_llvm_target(MyX86CodeGen ${sources}
        LINK_COMPONENTS
        MC
        AsmPrinter
        Core
        Support
        Target
        CodeGen
        SelectionDAG
        MyX86Info
        MyX86Desc

        ADD_TO_COMPONENT
        MyX86
)

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)


add_dependencies(LLVMMyX86CodeGen MyX86CommonTableGen)


message(${CMAKE_CURRENT_BINARY_DIR})
