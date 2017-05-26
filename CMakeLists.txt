project("Pancake Interpreter")

set(EXEC_NAME "pancake")

add_executable(
    ${EXEC_NAME}
    src/words.cpp
    src/token.cpp
    src/belt.cpp
    src/stack.cpp
    src/pancake.cpp)

install(TARGETS ${EXEC_NAME} RUNTIME DESTINATION bin)
