cmake_minimum_required(VERSION 3.15)
project(test2)

set(CMAKE_CXX_STANDARD 17)

add_executable(test2 main.cpp readers/ScheduleReader.cpp readers/ScheduleReader.h entities/Schedule.h utils/Time.cpp utils/Time.h entities/Company.h writers/ScheduleWriter.cpp writers/ScheduleWriter.h processors/ScheduleProcessor.cpp processors/ScheduleProcessor.h)