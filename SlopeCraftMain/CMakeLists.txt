cmake_minimum_required(VERSION 3.5)
project(SlopeCraft_Main VERSION ${SlopeCraft_version} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(${SlopeCraft_Eigen3_include_dir}
    ${CMAKE_SOURCE_DIR}/SlopeCraftL
    ${CMAKE_SOURCE_DIR}/utilities/BlockListManager)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools Network Concurrent REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools Network Concurrent REQUIRED)

set(SlopeCraftMain_windows_rc_file)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message("Configuring on Windows. Adding rc file to " ${PROJECT_NAME})
    configure_file(others/SlopeCraft.rc.in others/SlopeCraft.rc)
    set(SlopeCraftMain_windows_rc_file ${CMAKE_CURRENT_BINARY_DIR}/others/SlopeCraft.rc)
endif()

set(SlopeCraftMain_header_files
    AiCvterParameterDialog.h
    BatchUi.h
    TaskBox.h
    MainWindow.h
    previewwind.h
    tpstrategywind.h
)

set(SlopeCraftMain_source_files

    AiCvterParameterDialog.cpp
    BatchUi.cpp
    TaskBox.cpp
    main.cpp
    MainWindow.cpp
    previewwind.cpp
    tpstrategywind.cpp
)

set(SlopeCraftMain_ui_files

    AiCvterParameterDialog.ui
    BatchUi.ui
    mainwindow.ui
    previewwind.ui
    TaskBox.ui
    tpstrategywind.ui)

set(SlopeCraftMain_ts_files

    others/SlopeCraft_en_US.ts)

if(${SlopeCraft_update_ts_files})
    execute_process(
        COMMAND ${SlopeCraft_Qt_lupdate_executable} ${SlopeCraftMain_header_files} ${SlopeCraftMain_source_files} ${SlopeCraftMain_ui_files} "-ts" ${SlopeCraftMain_ts_files} ${SlopeCraft_ts_flags}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif()

set(SlopeCraftMain_qrc_files
    others/BlockTextures.qrc
    others/Pics.qrc

    # others/SlopeCraft_translation.qrc
)

set(SlopeCraftMain_project_sources
    ${SlopeCraftMain_header_files}
    ${SlopeCraftMain_source_files}

    ${SlopeCraftMain_ts_files}
    ${SlopeCraftMain_ui_files}
    ${SlopeCraftMain_qrc_files}
    ${SlopeCraftMain_windows_rc_file}
)

qt_add_executable(SlopeCraft
    MANUAL_FINALIZATION
    ${SlopeCraftMain_project_sources})

# execute_process(COMMAND "pause")
# qt_create_translation(SlopeCraftMain_qm_files ${CMAKE_CURRENT_SOURCE_DIR} ${SlopeCraftMain_ts_files})
qt_add_lrelease(SlopeCraft TS_FILES ${SlopeCraftMain_ts_files}
    QM_FILES_OUTPUT_VARIABLE SC_qm_files)

qt_add_resources(SlopeCraft "translations"
    PREFIX "/i18n"
    BASE ${CMAKE_CURRENT_BINARY_DIR}
    FILES ${SC_qm_files})

# qt6_add_resources(SlopeCraft "translation"
# PREFIX "/i18n"
# FILES
# ${SlopeCraftMain_qm_files}
# ${CMAKE_SOURCE_DIR}/CMakeLists.txt)
target_link_libraries(SlopeCraft
    PRIVATE
    BlockListManager
    SlopeCraftL
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Network
    Qt${QT_VERSION_MAJOR}::Concurrent
    VersionDialog
)

set_target_properties(SlopeCraft PROPERTIES
    VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_ICON_FILE SlopeCraftIconNew.icns
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.github.ToKiNoBug.SlopeCraft"
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(SlopeCraft)

include(install.cmake)