cmake_minimum_required(VERSION 3.23)
project(TrabalhoFinalPOO_22)

set(CMAKE_CXX_STANDARD 14)

add_executable(TrabalhoFinalPOO_22 main.cpp exceptions/InvalidArguments.h arguments/ArgsHandler.cpp arguments/ArgsHandler.h utils/utils.h exceptions/NotANumber.h exceptions/OutOfBounds.h utils/utils.cpp simulation/Simulation.cpp simulation/Simulation.h commands/Command.cpp commands/Command.h commands/CommandHandler.cpp commands/CommandHandler.h exceptions/CommandNotFound.h)
