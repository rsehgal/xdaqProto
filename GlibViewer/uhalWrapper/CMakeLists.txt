cmake_minimum_required(VERSION 2.8)

set(OUTDIR ${PROJECT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTDIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTDIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTDIR}/bin)

include_directories(inc)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules)
find_package(uHAL REQUIRED)
include_directories(${uHAL_INCLUDE_DIR})

#Below line may be uncommented later if more libraries are required
set(LIBS -lpthread -lboost_thread -lboost_filesystem -lboost_regex -lboost_system -lboost_thread -lboost_program_options -lcactus_extern_pugixml -lcactus_uhal_log -lcactus_uhal_grammars -lcactus_uhal_uhal)

#set(LIBS -lcactus_uhal_uhal)

add_library(glib SHARED inc/glib.h src/glib.cpp)
target_link_libraries(glib "-L ${uHAL_LIBRARY_DIR} ${LIBS}")

message(STATUS "=======================================================")
message(STATUS "Please set your LD_LIBRARY_PATH env variable as" )
message(STATUS "export LD_LIBRARY_PATH=${CMAKE_LIBRARY_OUTPUT_DIRECTORY}:$LD_LIBRARY_PATH")
message(STATUS "=======================================================")

add_executable(system tests/system.cpp)
target_link_libraries(system "-L ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} -lglib")

add_executable(sturdy tests/sturdy.cpp)
target_link_libraries(sturdy "-L ${uHAL_LIBRARY_DIR} ${LIBS}")
