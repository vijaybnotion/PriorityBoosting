/*
 * queue.h
 *
 *  Created on: 24-Jul-2022
 *      Author: vijay
 */

#ifndef INC_CUSTOMQUEUE_H_
#define INC_CUSTOMQUEUE_H_
#include "FreeRTOS.h"
#include "semphr.h"
#define MAX 5

typedef struct queueTaskHandle{
	TaskHandle_t arr[MAX];
	int front;
	int rear;
}queueTaskHandle;

typedef enum{
	ARRAY_IS_FULL = 0x55,
	ARRAY_IS_EMPTY = 0x56,
	ARRAY_OPERATION_SUCCESSFUL = 0x57
}queueStatus_t;

//typedef struct queueTaskHandle queueTaskHandle;

void initqueue(queueTaskHandle *);
queueStatus_t enqueue(queueTaskHandle *, TaskHandle_t);
queueStatus_t dequeue(queueTaskHandle *);


#endif /* INC_CUSTOMQUEUE_H_ */
