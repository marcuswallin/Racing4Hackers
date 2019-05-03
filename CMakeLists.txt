cmake_minimum_required(VERSION 3.6)
project(Racing4Hackers)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Game/HighScore.cc Track/Asphalt.cc Track/Grass.cc Game/Graphics.cc Vehicle/Car.cc Vehicle/Vehicle.cc Track/Track.cc Game/GameEngine.cc Game/StartMenu.cc Game/Racing4Hackers.cc Vehicle/Motorcycle.cc Other/Coordinate.cc Other/Coordinate.h Track/CheckPoint.h Track/TrackLine.cc Track/TrackLine.h)

add_executable(Racing_4_Hackers ${SOURCE_FILES})
target_link_libraries(Racing_4_Hackers sfml-graphics sfml-window sfml-system sfml-audio)
