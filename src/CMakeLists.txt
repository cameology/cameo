# main executable
set(MAIN ${CMAKE_CURRENT_SOURCE_DIR}/main)
set(TEST ${CMAKE_CURRENT_SOURCE_DIR}/test)

add_executable(gibbon_test ${TEST}/suites.cc)

# include dirs
target_include_directories(
    gibbon_test PRIVATE ${PROJECT_SOURCE_DIR}/kernels/includes
)

target_include_directories(
    gibbon_test PRIVATE ${MAIN}/kernels
)

# Test Suites
enable_testing()
set(GoogleTest ${PROJECT_SOURCE_DIR}/kernels/libs/googletest)

find_library(GTest gtest ${GoogleTest})
find_library(GTestMain gtest_main ${GoogleTest})
find_library(GMock gmock ${GoogleTest})

target_link_libraries(gibbon_test PRIVATE
    ${GTest}
    ${GTestMain}
    ${GMock}
)