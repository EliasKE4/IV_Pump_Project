#include "security.h"
#include "pressure_sensor.h"

extern QueueHandle_t motor_cmds_queue;
extern QueueHandle_t ui_queue;

void Security_Task(void *pvParameters){
    int current_pressure;
    int emergency_motor_cmd = 0;
    while (1) {
        Pressure_Read(&current_pressure);
        if (current_pressure > 60) {
            xQueueSendToFront(motor_cmds_queue, &emergency_motor_cmd, 0);
            xQueueSendToFront(ui_queue, &emergency_motor_cmd, 0);
        }
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}