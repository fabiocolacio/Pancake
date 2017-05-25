project("Pancake Interpreter")

set(EXEC_NAME "pancake")

add_executable(
    ${EXEC_NAME} 
    src/pancake.cpp)

install(TARGETS ${EXEC_NAME} RUNTIME DESTINATION bin)
