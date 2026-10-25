cmake_minimum_required(VERSION 3.10)
project(IV_Pump)

include_directories(inc)

set(SOURCES     
    src/main.c
    src/motor.c
    src/security.c
    src/ui.c
    FreeRTOS/tasks.c
    FreeRTOS/queue.c
    )

add_executable(iv_pump ${SOURCES})