#include <stdio.h>
#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

#include "ui.h"
#include "motor.h"
#include "security.h"

QueueHandle_t motor_cmds_queue;
QueueHandle_t ui_queue; 


int main (void){
    motor_cmds_queue = xQueueCreate(5, sizeof(int));
    ui_queue = xQueueCreate(5, sizeof(int));

    xTaskCreate(
        Motor_Task,
        "motor_logs",
        128,
        NULL,
        2,
        NULL
    );

    xTaskCreate(
        Security_Task,
        "security_logs",
        128,
        NULL,
        3,
        NULL
    );

    xTaskCreate(
        UI_Task,
        "ui_logs",
        128,
        NULL,
        1,
        NULL
    );

    vTaskStartScheduler();
    return 0;
}