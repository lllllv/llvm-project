add_llvm_component_library(LLVMMyX86Desc
        MyX86MCTargetDesc.cpp
        MyX86MCAsmInfo.cpp
        MyX86InstPrinter.cpp
        ADD_TO_COMPONENT
        MyX86

        LINK_COMPONENTS
        MC
        Core
        Support
        MyX86Info
)