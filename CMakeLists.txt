cmake_minimum_required(VERSION 3.21)
project(PROJET_TP1)

set(CMAKE_CXX_STANDARD 14)

add_executable(PROJET_TP1 main.cpp Lecteur.cpp Lecteur.h Emprunt.cpp Emprunt.h date.h date.cpp Bibliotheque.cpp Bibliotheque.h Auteur.h Auteur.cpp Livre.h Livre.cpp)
