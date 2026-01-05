cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Put executable in /bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# -----------------------------
# SFML
# -----------------------------
include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)
FetchContent_MakeAvailable(SFML)

# -----------------------------
# Source files (auto-collect)
# -----------------------------
file(GLOB_RECURSE SRC_FILES
    src/*.cpp
)

add_executable(main ${SRC_FILES})

# -----------------------------
# Include directories
# -----------------------------
target_include_directories(main
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# -----------------------------
# Link SFML
# -----------------------------
target_link_libraries(main
    PRIVATE
        SFML::Graphics
)

# -----------------------------
# Assets: copy to runtime folder
# -----------------------------
add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/assets
        $<TARGET_FILE_DIR:main>/assets
)

add_dependencies(main copy_assets)
