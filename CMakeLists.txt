cmake_minimum_required(VERSION 3.23)
project(cpp_chip8_emulator)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/)

include(FetchContent)
FetchContent_Declare(
        sfml
        URL https://www.sfml-dev.org/files/SFML-2.5.1-sources.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_GetProperties(sfml)
if (NOT sfml_POPULATED)
    message("Fetching SFML")
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif ()


add_executable(cpp-platformer src/main.cpp src/EmulatorWindow.cpp src/EmulatorWindow.h src/sharpSm83/SharpSm83.cpp src/sharpSm83/SharpSm83.h src/sharpSm83/GameBoyScreen.cpp src/sharpSm83/GameBoyScreen.h)

target_compile_features(cpp-platformer PRIVATE cxx_std_20)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT cpp-platformer)

target_link_libraries(cpp-platformer PRIVATE sfml-window sfml-audio sfml-system sfml-graphics)

add_custom_command(
        TARGET cpp-platformer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${sfml_SOURCE_DIR}/extlibs/bin/x64/openal32.dll ${CMAKE_CURRENT_BINARY_DIR}/)

# COMMAND ${CMAKE_COMMAND} -E copy_directory src/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
# COMMAND ${CMAKE_COMMAND} -E copy_directory src/shader ${CMAKE_CURRENT_BINARY_DIR}/shader

set_target_properties(cpp-platformer PROPERTIES CXX_EXTENSIONS OFF)
if (CMAKE_CXX_COMPILER_ID MATCHES MSVC) # MSVC
    target_compile_options(cpp-platformer PRIVATE /W4 /WX /permissive-)
elseif (CMAKE_CXX_COMPILER_ID MATCHES GNU) # GCC or MinGW
    target_compile_options(cpp-platformer PRIVATE -Wall -Wextra -Werror -pedantic -pedantic-errors -Wold-style-cast)
elseif (CMAKE_CXX_COMPILER_ID MATCHES Clang AND CMAKE_CXX_SIMULATE_ID MATCHES MSVC) # Clang-CL
    target_compile_options(cpp-platformer PRIVATE /W4 -Wextra -Werror -Wold-style-cast)
elseif (CMAKE_CXX_COMPILER_ID MATCHES Clang) # Clang
    target_compile_options(cpp-platformer PRIVATE -Wall -Wextra -Werror -pedantic -pedantic-errors -Wold-style-cast)
else ()
    message(WARNING "Unknown Compiler")
endif ()
