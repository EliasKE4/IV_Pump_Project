#ifndef SECURITY_H
#define SECURITY_H

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

void Security_Task(void *pvParameters);

#endif /* SECURITY_H */