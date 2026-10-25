#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>
#include "FreeRTOS.h
#include "task.h"
#include "queue.h"

typedef enum{
    MOTOR_OK,
    MOTOR_ERROR
} Motor_Status_t;

Motor_Status_t Motor_Set_Flow(int32_t flow);

void Motor_Task(void *pvParameters);

#endif /* MOTOR_H */