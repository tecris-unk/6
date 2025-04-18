//
// Created by intak on 16.04.2025.
//
#include "functions.h"
void createAndShowQueue()
{
    printf("Enter max size of queue: ");
    int maxSize;
    setNumber(&maxSize);
    Queue *queue = createQueue();
    for(int i = 0;i < 6; ++i)
    {
        printf("enter value to push in queue: ");
        int x;
        setNumber(&x);
        push(queue, x, maxSize);
        if(sizeQueue(queue) == maxSize){break;}
    }
    int answer = showToFirstNegative(queue);

    printf("There are %d elements more after negative element\n", answer);
    while(sizeQueue(queue) != 0)
    {
        pop(queue);
    }
}
void createAndShowDeque()
{
    printf("Enter max size of deque: ");
    int maxSize;
    setNumber(&maxSize);
    Deque *deque = createDeque();
    for(int i = 0;i < 6; ++i)
    {
        ((i & 1) == 0) ?
        printf("enter value to push in front of deque: "):
        printf("enter value to push in back of deque: ");

        int x;
        setNumber(&x);
        if(i&1)
            push_back(deque, x, maxSize);
        else
            push_front(deque, x, maxSize);

        showDeque(deque);
        if(sizeDeque(deque) == maxSize){break;}
    }
    int answer = showToFirstNegativeInDeque(deque);
    printf("There are a %d last elements after negative element\n", answer);
    while(sizeDeque(deque)!=0)
        pop_back(deque);
}
void FindSameQueues()
{

}