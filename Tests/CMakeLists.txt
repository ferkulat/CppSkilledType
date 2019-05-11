
set(SOURCE_FILES TestMain.cpp SkilledTypeTest.cpp)

add_executable(CppSkilledTypeTests ${SOURCE_FILES})
add_test(
        NAME CppSkilledTypeTests
        COMMAND CppSkilledTypeTests
)
