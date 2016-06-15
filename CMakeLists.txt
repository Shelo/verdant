cmake_minimum_required(VERSION 3.5)
project(verdant)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sources/lexer/Lexer.cpp sources/lexer/Lexer.hpp sources/lexer/types/Token.cpp sources/lexer/types/Token.hpp sources/lexer/types/Word.cpp sources/lexer/types/Word.hpp sources/lexer/types/String.cpp sources/lexer/types/String.hpp)
add_executable(verdant ${SOURCE_FILES})