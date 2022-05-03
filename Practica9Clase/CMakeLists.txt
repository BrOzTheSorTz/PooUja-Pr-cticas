cmake_minimum_required(VERSION 3.19)
project(prueba)

set(CMAKE_CXX_STANDARD 20)

FILE(GLOB SOURCE_FILES *.cpp)

ADD_EXECUTABLE(a.exe ${SOURCE_FILES} Espada.cpp Espada.h Filete.cpp Filete.h Bloque.cpp Bloque.h ItemApilable.cpp ItemApilable.h EmptyContainer.h ItemArrojable.h ItemApilableArrojable.h ItemApilableArrojable.cpp ItemAgotado.h BolaDeNieve.cpp BolaDeNieve.h)
