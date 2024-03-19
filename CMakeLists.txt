cmake_minimum_required(VERSION "3.16")
project("Fuel")

#------------------------------
#----------Fuel Build----------
#------------------------------

add_library("Fuel" STATIC
    "src/core/Platform.h"
    "src/core/Platform_linux.cpp"
    "src/core/Platform_win32.cpp"

    "src/config.h"
    "src/log.h"

    "src/main.h"
    "src/Fuel.h"
)

target_include_directories("Fuel" PUBLIC
    "src"
)

set_target_properties("Fuel" PROPERTIES LINKER_LANGUAGE CXX)

#------------------------------
#----------Test Build----------
#------------------------------

add_executable("Test"
    "Test/Test.cpp"
)

target_link_libraries("Test" PRIVATE
    "Fuel"
)

target_include_directories("Test" PUBLIC
    "src"
    "Test"
)