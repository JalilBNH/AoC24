add_executable(day-3 main.cpp)
target_link_libraries(day-3 PRIVATE aoc_toolbox)

set_target_properties(
    day-3 PROPERTIES 
    BUILD_RPATH "\$ORIGIN/../lib/aoc-toolbox"
    INSTALL_RPATH "\$ORIGIN/../lib/aoc-toolbox"
)