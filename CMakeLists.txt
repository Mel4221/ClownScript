cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)   # You can change this to 11, 14, 17, etc.
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Disable compiler-specific extensions
# Specify the C standard you want to ensure compatibility with
#set(CMAKE_C_STANDARD 11)      # Change this as needed
#set(CMAKE_C_STANDARD_REQUIRED ON)
#set(CMAKE_C_EXTENSIONS OFF)    # Disable compiler-specific extensions

# Set the project name and specify the languages used
project(ClownScript VERSION 0.0.1)


# Add your source files
#Collecting the SRC .cpp files from ClownScript
file(GLOB_RECURSE CLOWN_SCRIPT_CPP ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
#file(GLOB_RECURSE GrumpyTools_HPP ${CMAKE_CURRENT_SOURCE_DIR}include/*.hpp)
# Add your C source files
#set(C_SOURCES   src/compatibility_file.c  # Add your C source files here)

# Create the executable
add_executable(clownscript ${CLOWN_SCRIPT_CPP})

# Optionally, specify include directories
target_include_directories(clownscript PUBLIC include)

# Cross-platform settings
if (WIN32)
    # Windows-specific settings
    message(STATUS "Configuring for Windows")
elseif(APPLE)
    # macOS-specific settings
    message(STATUS "Configuring for macOS")
elseif(UNIX)
    # Unix/Linux-specific settings
    message(STATUS "Configuring for Unix/Linux")
endif()

# If you need to link with other libraries, add them here
# target_link_libraries(MyExecutable PRIVATE some_library)

# Set output directories
# set_target_properties(MyExecutable PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Optionally include a custom command for running tests or other post-build actions
# add_custom_command(TARGET MyExecutable POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E echo "Executable built successfully!"
# )
