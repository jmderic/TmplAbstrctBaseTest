# only one tested
cmake_minimum_required (VERSION 3.10)

project (Qstart)

# The version number.  (works with config file)
set (Qstart_MAJOR_VERSION 0)
set (Qstart_MINOR_VERSION 1)
set (Qstart_PATCH_VERSION 0)
set(Qstart_VERSION
  ${Qstart_MAJOR_VERSION}.${Qstart_MINOR_VERSION}.${Qstart_PATCH_VERSION})

# basic compile standards
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# finding distrib libraries we want

# none yet

## PROJECT specific

# creating the executable
set (Qstart_SOURCES
  main.cpp
  )

set (QstartC_SOURCES
  main.c
  )

include_directories(
  "${PROJECT_SOURCE_DIR}"
  )

# applies to all targets.  Maybe what we want?
# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra")

option (ASAN_ENABLED
  "Build with AddressSanitizer"
  OFF
  )

option (LSAN_ENABLED
  "Build with LeakSanitizer"
  OFF
  )

if(ASAN_ENABLED OR LSAN_ENABLED)
set (CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -fno-omit-frame-pointer")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer")
endif(ASAN_ENABLED OR LSAN_ENABLED)

if(ASAN_ENABLED)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")
endif(ASAN_ENABLED)

if(LSAN_ENABLED)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=leak")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=leak")
endif(LSAN_ENABLED)

## TARTGET specific

add_executable(Qstart ${Qstart_SOURCES})
target_compile_options(Qstart PRIVATE -Werror -Wall -Wextra)

add_executable(QstartC ${QstartC_SOURCES})
target_compile_options(QstartC PRIVATE -Werror -Wall -Wextra)
