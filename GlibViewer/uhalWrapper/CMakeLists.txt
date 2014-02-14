cmake_minimum_required(VERSION 2.8)
set(MYLIBROOT $ENV{MYLIBROOT})
set(OUTDIR ${PROJECT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MYLIBROOT}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTDIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTDIR}/bin)

include_directories(inc)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules)
find_package(uHAL REQUIRED)
include_directories(${uHAL_INCLUDE_DIR})

#Below line may be uncommented later if more libraries are required
set(LIBS -lpthread -lboost_thread -lboost_filesystem -lboost_regex -lboost_system -lboost_thread -lboost_program_options -lcactus_extern_pugixml -lcactus_uhal_log -lcactus_uhal_grammars -lcactus_uhal_uhal)

#set(LIBS -lcactus_uhal_uhal)

file(GLOB testsources tests/*.cpp)
file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/inc/*.h)
file(GLOB libsources src/*.cpp)

add_library(glib SHARED ${headers} ${libsources})
target_link_libraries(glib "-L ${uHAL_LIBRARY_DIR} ${LIBS}")

message(STATUS "=======================================================")
message(STATUS "Please set your LD_LIBRARY_PATH env variable as" )
message(STATUS "export LD_LIBRARY_PATH=${CMAKE_LIBRARY_OUTPUT_DIRECTORY}:$LD_LIBRARY_PATH")
message(STATUS "=======================================================")

foreach( test  ${testsources} )
        get_filename_component( TESTEXEC  ${test} NAME_WE)
        add_executable(${TESTEXEC} ${test})
        target_link_libraries(${TESTEXEC} "-L ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} -lglib")
endforeach( test  )

