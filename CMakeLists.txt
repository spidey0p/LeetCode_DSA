cmake_minimum_required(VERSION 3.25)
project(Leet_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Leet_code
        D1/4sum.cpp
        D1/duplictNumber.cpp
        D1/max_sum_subarray.cpp
        D1/Q1.cpp
        Day2/AggressiveCow.cpp
        Day2/anagrams.cpp
        Day2/binSerch.cpp
        Day2/deleteLastNodeLL.cpp
        Day2/findKthElement.cpp
        Day2/findPeakElement.cpp
        Day2/fourSum.cpp
        Day2/lastOccurrence.cpp
        Day2/majorityElement.cpp
        Day2/max.cpp
        Day2/maxProductSubarray.cpp
        Day2/meargeSortedArray.cpp
        Day2/medianOFtwoArray.cpp
        Day2/medianOfTwoSortedArray.cpp
        Day2/mergeOverlaping.cpp
        Day2/minINrotateArray.cpp
        Day2/minInRotedArray.cpp
        Day2/NthRootOFaNumber.cpp
        Day2/numOfProvienses.cpp
        Day2/queue_implementation.cpp
        Day2/reversePair.cpp
        Day2/rottenORANGE.cpp
        Day2/searchRotateArray.cpp
        Day2/stack_implementation.cpp
        Day2/threeSum.cpp
        Day2/ThreeSum_Optimize.cpp
        DP-Striver/ClimbingStairs.cpp
        DP-Striver/FrogJump.cpp
        DP-Striver/FrogJumpK-steps.cpp
        DP-Striver/GridUniquepath2.cpp
        DP-Striver/GridUniquePaths.cpp
        DP-Striver/MinMaxFallingPathSum.cpp
        DP-Striver/MinmPathSum.cpp
        DP-Striver/MinPathSumTraingle.cpp)
