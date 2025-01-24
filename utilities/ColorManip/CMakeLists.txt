project(ColorManip VERSION ${SlopeCraft_version} LANGUAGES C CXX)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include_directories(../SlopeCraftL)
find_package(OpenMP REQUIRED)

add_library(ColorManip

    ColorManip.h
    ColorCvt.cpp
    ColorDiff.cpp
    CIEDE00.cpp

    newColorSet.hpp
    newTokiColor.hpp
    StaticMembers.cpp

    colorset_maptical.hpp
    imageConvert.hpp
    newColorSet.hpp
    newTokiColor.hpp
)

target_compile_features(ColorManip PUBLIC cxx_std_20)

# set_target_properties(ColorManip PROPERTIES CXX_STANDARD_REQUIRED ON)

# get_target_property(cm_cxx_std ColorManip CXX_STANDARD)
# message(STATUS "cm_cxx_std = " ${cm_cxx_std})
target_include_directories(ColorManip PUBLIC
    ${SlopeCraft_Eigen3_include_dir}
    ${CMAKE_SOURCE_DIR}/utilities)

target_include_directories(ColorManip PRIVATE
    ${SlopeCraft_HeuristicFlow_include_dir})

target_link_libraries(ColorManip PUBLIC OpenMP::OpenMP_CXX)

# target_compile_options(ColorManip BEFORE PUBLIC "-std=c++17")
target_compile_options(ColorManip PRIVATE ${SlopeCraft_vectorize_flags})

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
    set_target_properties(ColorManip PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
endif()

# ColorManip links to GPUInterface
target_link_libraries(ColorManip PUBLIC GPUInterface)
target_include_directories(ColorManip INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(OpenCL 3.0)

if(${OpenCL_FOUND})
    add_executable(test_init_program tests/test_init_program.cpp)
    target_link_libraries(test_init_program PRIVATE OpenMP::OpenMP_CXX ColorManip)

    add_executable(test_algo tests/test_algo.cpp)
    target_link_libraries(test_algo PRIVATE OpenMP::OpenMP_CXX ColorManip)

    include(${CMAKE_SOURCE_DIR}/cmake/configure_cli11.cmake)
    target_include_directories(test_algo PRIVATE ${cli11_include_dir})

    foreach(_algo r R H X l L)
        add_test(NAME test_algo_${_algo}
            COMMAND test_algo --algo ${_algo} --platform-idx 0 --device-idx 0
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
    endforeach(_algo r R H X l L)
endif()
