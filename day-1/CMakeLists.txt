add_executable(day-1 main.cpp)
target_link_libraries(day-1 PRIVATE aoc_toolbox)

set_target_properties(
    day-1 PROPERTIES 
    BUILD_RPATH "\$ORIGIN/../lib/aoc-toolbox"
    INSTALL_RPATH "\$ORIGIN/../lib/aoc-toolbox"
)