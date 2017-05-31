project(cpplib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SOURCE_CPPLIB Alm_Base.cpp aml.cpp Cl_Base.cpp constants.cpp Map_Base.cpp parameters.cpp)
set(HEADER_CPPLIB Alm_Base.hpp aml.cpp Cl_Base.hpp constants.hpp Map_Base.hpp parameters.hpp)

add_library(cpplib STATIC ${SOURCE_CPPLIB} ${HEADER_CPPLIB})
