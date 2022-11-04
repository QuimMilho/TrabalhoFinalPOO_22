cmake_minimum_required(VERSION 3.23)
project(TrabalhoFinalPOO_22)

set(CMAKE_CXX_STANDARD 14)

add_executable(TrabalhoFinalPOO_22 main.cpp commands/ComandHandler.cpp commands/ComandHandler.h args/ArgsHandler.cpp args/ArgsHandler.h simulacao/Simulacao.cpp simulacao/Simulacao.h exceptions/InvalidArguments.cpp exceptions/InvalidArguments.h utils/utils.cpp utils/utils.h exceptions/NotANumber.cpp exceptions/NotANumber.h)
