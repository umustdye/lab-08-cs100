CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    src/unit_test.cpp
    src/add_test.cpp
    src/mult_test.cpp
    src/sub_test.cpp
    src/div_test.cpp
    src/rand_test.cpp
    src/pow_test.cpp
)

ADD_EXECUTABLE(lab
    src/main.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
