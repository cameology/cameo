set(FRONTEND ${MAIN}/frontend)


add_library(frontend
    ${FRONTEND}/Lexer.cc
)

target_include_directories(frontend PRIVATE ${MAIN})