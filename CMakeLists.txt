cmake_minimum_required(VERSION 3.14)

project(blackjack)

if(WIN32)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:msvcrtd")
      message(STATUS "Rwindows settings")


endif()

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set runtime library to be consistent

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug") # Use MTd (static debug runtime)
    message(STATUS "Runtime library set to: ${CMAKE_MSVC_RUNTIME_LIBRARY}")
endif()

#set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")
#message(STATUS "Runtime library set to: ${CMAKE_MSVC_RUNTIME_LIBRARY}")

# Add main executable
add_executable(
    blackjack
    src/blackjack.cpp
    src/card.cpp
    src/dealer.cpp
    src/deck.cpp
    src/game.cpp
    src/human.cpp
    src/player.cpp
    src/print.cpp
    src/statistics.cpp
    src/compatible.cpp
 "src/ConsoleCard.cpp")

# Enable testing
enable_testing()
message(STATUS "Testing enabled.")

# Check for CTest
find_program(CTest_EXECUTABLE ctest)
if(CTest_EXECUTABLE)
    message(STATUS "CTest found at: ${CTest_EXECUTABLE}")
else()
    message(WARNING "CTest not found. Attempting to download and include it.")
    
    # Use FetchContent to download CMake (includes CTest)
    include(FetchContent)
    FetchContent_Declare(
        cmake_ctest
        URL https://github.com/Kitware/CMake/releases/download/v3.27.4/cmake-3.27.4-windows-x86_64.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    FetchContent_MakeAvailable(cmake_ctest)
    find_program(CTest_EXECUTABLE ctest PATHS ${cmake_ctest_SOURCE_DIR}/bin)
    if(CTest_EXECUTABLE)
        message(STATUS "Downloaded and included CTest: ${CTest_EXECUTABLE}")
    else()
        message(FATAL_ERROR "CTest could not be found or downloaded.")
    endif()
endif()

# Include FetchContent for Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)
message(STATUS "Google Test downloaded and made available.")

if(MSVC)
    set_target_properties(gtest PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
    set_target_properties(gtest_main PROPERTIES MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
endif()


# Ensure consistent flags for Google Test
if(MSVC)
    message(STATUS "Configuring Google Test for MSVC with runtime library: ${CMAKE_MSVC_RUNTIME_LIBRARY}")
    set_target_properties(gtest PROPERTIES
        MSVC_RUNTIME_LIBRARY ${CMAKE_MSVC_RUNTIME_LIBRARY}
    )
    set_target_properties(gtest_main PROPERTIES
        MSVC_RUNTIME_LIBRARY ${CMAKE_MSVC_RUNTIME_LIBRARY}
    )
endif()

# Add test executable
# This is the executable that will run the tests for the blackjack game
# It will be linked with Google Test 
# It will also include the source files and headers
# It will be built in the tests directory
# You will need to add any new files to this list so that the test executable can access them

add_executable(
    blackjack_tests
    tests/blackjack_test.cpp
    src/card.cpp
    src/deck.cpp
    src/game.cpp
    src/human.cpp
    src/player.cpp
    src/print.cpp
    src/statistics.cpp
    src/compatible.cpp
    src/dealer.cpp
 "src/ConsoleCard.cpp")



# ensures that the tests can read from the src and header files
target_include_directories(blackjack_tests PRIVATE "${CMAKE_SOURCE_DIR}/src" "${CMAKE_SOURCE_DIR}/src/headers")




# Link Google Test to the test executable
target_link_libraries(blackjack_tests PRIVATE gtest_main)
message(STATUS "Test executable linked with Google Test.")



# Add test cases
add_test(NAME BlackjackTests COMMAND blackjack_tests)
message(STATUS "Test case 'BlackjackTests' added.")

# Attempt to run tests after the build
if(CTest_EXECUTABLE)
    add_custom_target(
        run_tests
        COMMAND ${CTest_EXECUTABLE} --output-on-failure
        DEPENDS blackjack_tests
        COMMENT "Running tests after build."
    )
    message(STATUS "CTEST good to go")


else()
    message(WARNING "CTest is not available; tests will not be run automatically.")
endif()

set(GTEST_DISCOVER_TESTS_DISCOVERY_MODE PRE_TEST)


# Print final message
message(STATUS "CMake configuration complete. Ready to build.")
