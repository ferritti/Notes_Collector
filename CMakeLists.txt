cmake_minimum_required(VERSION 3.25)
project(Notes_Manager)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Test)

set(SOURCE_FILES Observer.h Subject.h Note.cpp Note.h NotesCollection.h NotesCollection.cpp ControlPanel.h ControlPanel.cpp)
add_executable(Notes_Manager main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Notes_Manager core)