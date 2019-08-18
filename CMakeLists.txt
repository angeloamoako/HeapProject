cmake_minimum_required(VERSION 3.10)
project(HeapTemp)
set(CMAKE_CXX_STANDARD 14)

# ------------------------------------------------------------------------------
### COMPILER FLAGS ###
if (CMAKE_BUILD_TYPE STREQUAL "Debug") # "Debug" mode
    add_compile_options("-g")
    if (CMAKE_COMPILER_IS_GNUCXX) # if compiler is gcc
        add_compile_options("-ggdb3")
    elseif (CMAKE_CXX_COMPILER_ID EQUAL "Clang") # if compiler is clang
        add_compile_options("-fsanitize=address")
        add_compile_options("-fno-omit-frame-pointer")
    endif()
endif()

add_compile_options("-Wall")
add_compile_options("-Wextra")
add_compile_options("-Wpedantic")

# ------------------------------------------------------------------------------
## BUILD LIBRARY ##
include_directories(${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/lib)

add_executable(heaptest  test/Test.cpp)

install(TARGETS heaptest DESTINATION ${PROJECT_SOURCE_DIR}/bin)

# ------------------------------------------------------------------------------
### CUSTOM TARGETS ###
add_custom_target(clean-all
        COMMAND rm -rf ${PROJECT_SOURCE_DIR}/build/*
        COMMAND rm -rf ${PROJECT_SOURCE_DIR}/docs/*
        COMMENT "Elimina i file intermedi e la documentazione")

find_program(DOXYGEN_FOUND doxygen)
if (DOXYGEN_FOUND)
    add_custom_target(doc
            COMMAND doxygen ${PROJECT_SOURCE_DIR}/Doxyfile.conf
            COMMENT "Carica la documentazione")
endif()

# ------------------------------------------------------------------------------
### TESTS ###

enable_testing()

find_program(VALGRIND_FOUND valgrind)

ADD_TEST(NAME CompileTest
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
        COMMAND make heaptest)

ADD_TEST(NAME HeapIntegrity
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
        COMMAND ./heaptest [isHeap])

ADD_TEST(NAME NotHeapCheck
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
        COMMAND ./heaptest [notHeap])

ADD_TEST(NAME TopAndPop
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
        COMMAND ./heaptest [top/pop])

ADD_TEST(NAME CopyAndOperator+
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
        COMMAND ./heaptest [copy/size])

ADD_TEST(NAME TestPolymorphism
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
        COMMAND ./heaptest [Polymorphism])

find_program(VALGRIND_FOUND valgrind)

if (VALGRIND_FOUND)
    ADD_TEST(NAME ValgrindTest1
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
            COMMAND valgrind --leak-check=full --show-leak-kinds=all
            --error-exitcode=3
            --track-origins=yes
            ./heaptest [isHeap])

    ADD_TEST(NAME ValgrindTest2
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
            COMMAND valgrind --leak-check=full --show-leak-kinds=all
            --error-exitcode=3
            --track-origins=yes
            ./heaptest [notHeap])

    ADD_TEST(NAME ValgrindTest3
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
            COMMAND valgrind --leak-check=full --show-leak-kinds=all
            --error-exitcode=3
            --track-origins=yes
            ./heaptest [top/pop])


    ADD_TEST(NAME ValgrindTest4
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
            COMMAND valgrind --leak-check=full --show-leak-kinds=all
            --error-exitcode=3
            --track-origins=yes
            ./heaptest [copy/+])

    ADD_TEST(NAME ValgrindTest5
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/build
            COMMAND valgrind --leak-check=full --show-leak-kinds=all
            --error-exitcode=3
            --track-origins=yes
            ./heaptest [Polymorphism])

endif()