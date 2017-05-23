set(CMAKE_CXX_FLAGS "-Weverything -Ofast")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

get_filename_component(test_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" test_name ${test_name})
project(${test_name})

add_executable(${test_name} src/main.cpp)

target_link_libraries(${test_name} lib)