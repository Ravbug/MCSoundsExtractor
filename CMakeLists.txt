cmake_minimum_required(VERSION 3.17)   

project("MCSoundsExtractor")
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIGURATION>)

file(GLOB SRC "src/*.cpp" "src/*.hpp" "src/*.h")
if(APPLE)
    set(macfiles "src/wxmac.icns" CACHE INERNAL "")
endif()
add_executable("${PROJECT_NAME}" WIN32 ${SRC} ${macfiles})

#wxwidgets
set(wxBUILD_SHARED OFF CACHE INTERNAL "")
add_subdirectory("wxWidgets")

#rapidjson
target_include_directories("${PROJECT_NAME}" PUBLIC "rapidjson/include")

target_link_libraries("${PROJECT_NAME}"
    PUBLIC 
    wx::base
	wx::core
)

# mac app
set_target_properties("${PROJECT_NAME}" PROPERTIES 
    MACOSX_BUNDLE ON
    MACOSX_BUNDLE_INFO_PLIST "${CMAKE_CURRENT_LIST_DIR}/src/Info.plist"
)
set_source_files_properties("${CMAKE_CURRENT_LIST_DIR}/src/wxmac.icns" PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
INSTALL(CODE 
		"include(BundleUtilities)
		fixup_bundle(\"${CMAKE_INSTALL_PREFIX}/$<CONFIGURATION>/${APPNAME}.app\" \"\" \"\")
		" 
		COMPONENT Runtime
	)

# windows app
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DPI_AWARE "PerMonitor")
