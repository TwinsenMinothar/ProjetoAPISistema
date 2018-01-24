cmake_minimum_required(VERSION 3.9)
project(ProjetoAPISistema)

set(CMAKE_CXX_STANDARD 11)

add_executable(ProjetoAPISistema Fluxo.h Sistema.h Modelo.h test.cpp FluxoImp.cpp FluxoImp.h SistemaImp.cpp SistemaImp.h ModeloImp.cpp ModeloImp.h)