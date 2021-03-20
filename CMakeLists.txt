cmake_minimum_required(VERSION 3.17)   

project("MCSoundsExtractor") 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB MY_SOURCES "src/*.cpp" "src/*.hpp" "src/*.h")
add_executable("${PROJECT_NAME}" ${MY_SOURCES})

#wxwidgets
add_subdirectory("wxWidgets")

#rapidjson
target_include_directories("${PROJECT_NAME}" PUBLIC "rapidjson/include")

target_link_libraries("${PROJECT_NAME}"
    PUBLIC 
    wx::base
)

# mac app
set_target_properties("${PROJECT_NAME}" PROPERTIES 
    MACOSX_BUNDLE ON
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_LIST_DIR}/src/Info.plist"
)
set_source_files_properties("src/wxmac.icns" PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")

