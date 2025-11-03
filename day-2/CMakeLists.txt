add_executable(day-2 main.cpp)
target_link_libraries(day-2 PRIVATE aoc_toolbox)

set_target_properties(
    day-2 PROPERTIES 
    BUILD_RPATH "\$ORIGIN/../lib/aoc-toolbox"
    INSTALL_RPATH "\$ORIGIN/../lib/aoc-toolbox"
)