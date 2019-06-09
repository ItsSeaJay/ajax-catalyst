set(EXECUTABLE_NAME
	${PROJECT_NAME}Server)

# Create lists of all the source files used by this section of the project
set(SOURCES
	src/main.cpp
	src/Server.cpp)
set(INCLUDES
	include/AjaxCatalyst/Server/Server.h)

# Find SFML
find_package(SFML 2.5 COMPONENTS system graphics window network REQUIRED)

# Add the include directories for this executable
include_directories(include)

# Add an executable to the project
add_executable(${EXECUTABLE_NAME}
	${SOURCES}
	${INCLUDES})

# Link the necessary libaries to the above executable file
# SFML
target_link_libraries(${EXECUTABLE_NAME}
	sfml-system
	sfml-graphics
	sfml-window
	sfml-network)

# Also remember to link the psthread dependancy on Unix systems for concurrency
if (UNIX)
	target_link_libraries(${EXECUTABLE_NAME} pthread)
endif (UNIX)