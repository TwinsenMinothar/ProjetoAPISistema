cmake_minimum_required(VERSION 3.9)
project(ProjetoAPISistema)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProjetoAPISistema Fluxo.cpp Fluxo.h Sistema.cpp Sistema.h Modelo.cpp Modelo.h test.cpp)