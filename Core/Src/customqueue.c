/*
 * queue.c
 *
 *  Created on: 24-Jul-2022
 *      Author: vijay
 */


#include <customqueue.h>



void initqueue(queueTaskHandle * queue){
	queue->front = queue->rear = -1;
}

queueStatus_t enqueue(queueTaskHandle * queue, TaskHandle_t task){
	if((queue->rear == MAX-1 && queue->front == 0) || (queue->rear+1 == queue->front)){
		return ARRAY_IS_FULL;
	}

	if(queue->rear == MAX-1){
		queue->rear = 0;
	}else{
	queue->rear = queue->rear+1;
	}
	queue->arr[queue->rear] = task;

	if(queue->front == -1){
		queue->front = 0;
	}
	return ARRAY_OPERATION_SUCCESSFUL;
}


queueStatus_t dequeue(queueTaskHandle *queue){
	if(queue->front == -1){
		return ARRAY_IS_EMPTY;
	}
	queue->arr[queue->front] = 0;
	if(queue->front == queue->rear){
		initqueue(queue);
	}
	else{
		if(queue->front == MAX-1){
			queue->front = 0;
		}else{
		(queue->front)++;
		}
	}
	return ARRAY_OPERATION_SUCCESSFUL;
}

