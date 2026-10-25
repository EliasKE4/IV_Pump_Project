#include "ui.h"
#include "LCD.h"

extern QueueHandle_t motor_cmds_queue;
extern QueueHandle_t ui_queue;

void UI_Task(void *pvParameters){
    int flow = 50;
    while (1) {
        xQueueSend(motor_cmds_queue, &flow, 0);
        LCD_Display(&flow);
        xQueueReceive(ui_queue, &flow, 0);
        vTaskDelay(pdMS_TO_TICKS(100));
    } 
}