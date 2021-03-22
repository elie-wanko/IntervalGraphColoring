cmake_minimum_required(VERSION 3.17)
project(HeuristicIntervalColoring)

set(CMAKE_CXX_STANDARD 14)

add_executable(HeuristicIntervalColoring
        main.cpp
        utils/AdjacencyMatrix.cpp
        utils/AdjacencyMatrix.h
        utils/WeightVector.cpp
        utils/WeightVector.h
        utils/NodesOrdering.h
        utils/IntervalColoring.h
        helpers/Helpers.h)