project(lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(SOURCE_LIB aml.cpp constants.cpp correlation.cpp distance.cpp fft.cpp functionals.cpp functionals_p.cpp io.cpp monte.cpp
        parameters.cpp pml.cpp spectra.cpp utils.cpp)
set(HEADER_LIB aml.hpp constants.hpp correlation.hpp distance.hpp fft.hpp functionals.hpp functionals_p.hpp io.hpp monte.hpp
        parameters.hpp pml.hpp spectra.hpp utils.hpp)

add_library(lib STATIC ${SOURCE_LIB} ${HEADER_LIB})