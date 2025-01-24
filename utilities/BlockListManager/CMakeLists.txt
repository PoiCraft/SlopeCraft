cmake_minimum_required(VERSION 3.5)
project(SlopeCraft_BlockListManager VERSION ${SlopeCraft_version} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools REQUIRED)

include_directories(${CMAKE_SOURCE_DIR})

include(${CMAKE_SOURCE_DIR}/cmake/find_nlohmann_json.cmake)

set(BlockListManager_header_files

    BlockListManager.h
    BlockListManager_global.h
    TokiBaseColor.h
    TokiBlock.h)

set(BlockListManager_source_files

    BlockListManager.cpp
    TokiBaseColor.cpp
    TokiBlock.cpp
    BLM_preset.cpp)

set(BlockListManager_ts_files
    ${CMAKE_CURRENT_SOURCE_DIR}/BlockListManager_en_US.ts
)

if(${SlopeCraft_update_ts_files})
    execute_process(
        COMMAND ${SlopeCraft_Qt_lupdate_executable} ${BlockListManager_header_files} ${BlockListManager_source_files} "-ts" ${BlockListManager_ts_files} ${SlopeCraft_ts_flags}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()

set(BlockListManaer_project_sources
    ${BlockListManager_header_files}
    ${BlockListManager_source_files}
    ${BlockListManager_ts_files}
)

include_directories(../SlopeCraftL)

add_library(BlockListManager STATIC ${BlockListManaer_project_sources})
target_link_libraries(BlockListManager PUBLIC Qt${QT_VERSION_MAJOR}::Widgets SlopeCraftL)
target_compile_definitions(BlockListManager PRIVATE BlockListManager_LIBRARY)
target_include_directories(BlockListManager PRIVATE ${SlopeCraft_Nlohmann_json_include_dir})

qt_add_lrelease(BlockListManager TS_FILES ${BlockListManager_ts_files}
    QM_FILES_OUTPUT_VARIABLE BlockListManager_qm_files)
qt_add_resources(BlockListManager "BLM_translations"
    PREFIX "/i18n"
    BASE ${CMAKE_CURRENT_BINARY_DIR}
    FILES ${BlockListManager_qm_files})

# add_library(cmake_qt_lib STATIC  Cmake_qt_lib.cpp  Cmake_qt_lib.h)

# target_link_libraries(cmake_qt_lib PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# target_compile_definitions(cmake_qt_lib PRIVATE CMAKE_QT_LIB_LIBRARY)
