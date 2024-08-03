cmake_minimum_required(VERSION 3.10)
project(PostgreSQL VERSION 14.5)

# Set the build type (Debug or Release)
set(CMAKE_C_STANDARD  99)

# Add the PostgreSQL source directories
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIRS "${SOURCE_DIR}/include")

# Specify the PostgreSQL libraries and headers location
set(LIBRARY_DIRS "${SOURCE_DIR}/backend")

# Include directories for the compiler to search for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include/*)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/include/*/*)
file(GLOB_RECURSE POSTGRESQL_SRC_FILES
        src/*/*.c
        src/*/*.h
        src/*.c
        src/*.h
        src/*/*.c
        contrib/*/*.c)
# Set the compiler flags if necessary
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


# Add subdirectories to build
#[[add_subdirectory("${SOURCE_DIR}/backend")
add_subdirectory("${SOURCE_DIR}/interfaces/libpq")
add_subdirectory("${SOURCE_DIR}/contrib")]]

# Add any custom targets here
add_executable(postgres_server ${POSTGRESQL_SRC_FILES} )
target_link_libraries(postgres_server ${LIBRARIES})

# You may need to add more subdirectories and targets based on your needs.