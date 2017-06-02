project("Pancake Interpreter")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(EXEC_NAME "pancake")

add_executable(
    ${EXEC_NAME}
    src/environment.cpp
    src/words.cpp
    src/token.cpp
    src/belt.cpp
    src/stack.cpp
    src/pancake.cpp)

install(TARGETS ${EXEC_NAME} RUNTIME DESTINATION bin)
