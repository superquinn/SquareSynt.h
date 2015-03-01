cmake_minimum_required(VERSION 2.8.4)
project(SquareSynth)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Synth/SquareSynth.cpp Synth/SquareSynth.h Synth/SquareSynthNoteDefs.h Synth/Synth.ino)
