cmake_minimum_required(VERSION 3.25)
project(Notes_Manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(Notes_Manager main.cpp Observer.h Subject.h Note.h Note.h Note.cpp NotesCollection.h NotesCollection.cpp ControlPanel.h ControlPanel.cpp)
