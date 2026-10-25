#include "motor.h"

extern QueueHandle_t motor_cmds_queue;

Motor_Status_t Motor_Set_Flow(int32_t flow){
    return MOTOR_OK;
}

void Motor_Task(void *pvParameters){    
    int current_flow = 0;
    Motor_Status_t motor_status;
    while (1) {
        xQueueReceive(motor_cmds_queue, &current_flow, portMAX_DELAY);
        motor_status = Motor_Set_Flow(current_flow);
        switch (motor_status) {
            case MOTOR_OK:
                break;
            case MOTOR_ERROR:
                // Raise error
                break;       
        }
    }
}