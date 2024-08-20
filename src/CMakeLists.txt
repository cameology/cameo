# main executable
set(MAIN ${CMAKE_CURRENT_SOURCE_DIR}/main)
set(TESTS ${CMAKE_CURRENT_SOURCE_DIR}/tests)

add_executable(gibbon ${MAIN}/gibbon.cc)
add_executable(gibbon_test ${TESTS}/unit.cc)

# Link to submodules
target_link_libraries(gibbon PRIVATE)

# Test Suites
enable_testing()
target_link_libraries(gibbon_test PRIVATE gtest gtest_main)