//
// Created by intak on 16.04.2025.
//

#ifndef INC_6_FUNCTIONS_H
#define INC_6_FUNCTIONS_H

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <limits.h>
//#include <string.h>
//#include <ctype.h>

#include "queue.h"

void setNumber(int* number);
int getAnswer();
int max(int first, int second);
int min(int first, int second);

Queue* createQueue();
void push(Queue* queue, int value, int maxSize);
int pop(Queue *queue);
void show(Queue* queue);
int sizeQueue(Queue* queue);
int showToFirstNegative(Queue* queue);

Deque* createDeque();
void push_back(Deque* deque, int value, int maxSize);
void push_front(Deque* deque, int value, int maxSize);
int sizeDeque(Deque* deque);
int showToFirstNegativeInDeque(Deque* deque);
int pop_back(Deque* deque);
int pop_front(Deque* deque);
void showDeque(Deque* deque);

int isSame(Queue* queue1, Queue* queue2);

void createAndShowQueue();
void createAndShowDeque();
void FindSameQueues();

#endif //INC_6_FUNCTIONS_H
