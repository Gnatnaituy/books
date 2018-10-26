cmake_minimum_required(VERSION 3.7)
project(DataStructureAndAlgorithm)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(LinearDataStructure DIR_LDS)
aux_source_directory(LinearDataStructureProblems DIR_LDSP)

add_executable(DataStructureAndAlgorithm main.cpp ${DIR_LDS} ${DIR_LDSP})