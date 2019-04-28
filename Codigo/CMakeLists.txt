cmake_minimum_required(VERSION 3.13)
project(Etapa_0 C CXX ASM)
set(CMAKE_CXX_STANDARD 11)

enable_language(ASM_NASM)

#Esto es para poder debuggear asm (bueno, lo poco que se puede con nasm)
set(CMAKE_ASM_NASM_OBJECT_FORMAT elf64)
set(CMAKE_ASM_NASM_COMPILE_OBJECT "<CMAKE_ASM_NASM_COMPILER> <INCLUDES> \
    <FLAGS> -f ${CMAKE_ASM_NASM_OBJECT_FORMAT} -o <OBJECT> <SOURCE>")
set_source_files_properties(ASM/IO/iodualis.asm ASM/Conversion/convcatena.asm PROPERTIES COMPILE_FLAGS "-g -Fdwarf ")

#No se hacer PIE (no mae, no es el postre)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -no-pie")


add_executable(Etapa_0
        ASM/IO/ionumerus.asm
        ASM/IO/ioimago.asm
        ASM/IO/iocatena.asm
        ASM/IO/iodualis.asm
        ASM/IO/iofractio.asm
        ASM/IO/ioliber.asm
        ASM/IO/iodiem.asm

        ASM/Conversion/convnumerus.asm
        ASM/Conversion/convimago.asm
        ASM/Conversion/convdualis.asm
        ASM/Conversion/convfractio.asm
        ASM/Conversion/convcatena.asm


        main.cpp)