cmake_minimum_required(VERSION 2.8)

set(APP guess-word)
project(${APP})

message("Project: ${PROJECT_NAME}")

set(GW_SOURCE ai.c dict.c game.c human.c main.c word.c)
set(GW_HEADER ai.h dict.h game.h human.h word.h)

add_executable(${APP} ${GW_SOURCE})
