# Set the name of the executable file
set(EXECUTABLE_NAME
	${PROJECT_NAME}Client) # This should resolved to `AjaxCatalystClient`

# Link all of the appropriate source files
set(SOURCES
	src/main.cpp)

# Find the appropriate version of SFML
# If the package can't be found, terminate the script
find_package(SFML 2.5 COMPONENTS system graphics window audio network REQUIRED)

# Add the include directories for this executable
include_directories(include)

# Add an executable to the project
add_executable(${EXECUTABLE_NAME}
	${SOURCES})

# Link the libraries to the given executable
target_link_libraries(${EXECUTABLE_NAME}
	sfml-system
	sfml-graphics
	sfml-window
	sfml-audio
	sfml-network)

if (UNIX)
	target_link_libraries(${EXECUTABLE_NAME} pthread)
endif (UNIX)