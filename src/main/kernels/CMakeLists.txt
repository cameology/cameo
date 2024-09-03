set(KERNELS ${MAIN}/kernels)


add_library(kernels
    ${KERNELS}/exception.cc
)

target_include_directories(kernels PRIVATE ${MAIN})