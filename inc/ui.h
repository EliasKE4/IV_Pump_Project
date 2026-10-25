#ifndef UI_H
#define UI_H

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void UI_Task(void *pvParameters);

#endif /* UI_H */