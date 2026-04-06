add_llvm_component_library(LLVMMyX86Info
        MyX86TargetInfo.cpp
        LINK_COMPONENTS
        MC
        Support

        ADD_TO_COMPONENT
        MyX86
)