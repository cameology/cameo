set(FRONTEND ${MAIN}/frontend)


add_library(frontend
    ${FRONTEND}/lexer.cc
    ${FRONTEND}/ast.cc
)

target_include_directories(frontend PRIVATE ${MAIN})