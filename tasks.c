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
    Queue *queue1, *queue2, *queue3;
    queue1 = createQueue();
    queue2 = createQueue();
    queue3 = createQueue();
    // МЕНЮШКА
    printf(
            "1 - add object in first queue\n"
            "2 - add object in second queue\n"
            "3 - add object in third stack\n"
            "4 - find same queues\n"
            "5 - exit task\n"
    );
    while(1)
    {
        printf("what would you like to do\n");
        int ch = getch();
        int data;
        switch(ch)
        {
            case '1':
                printf("Enter new element for first queue\n");
                setNumber(&data);
                push(queue1, data, INT_MAX);
                show(queue1);
                break;
            case '2':
                printf("Enter new element for second queue\n");
                setNumber(&data);
                push(queue2, data, INT_MAX);
                show(queue2);
                break;
            case '3':
                printf("Enter new element for third queue\n");
                setNumber(&data);
                push(queue3, data, INT_MAX);
                show(queue3);
                break;
            case '4':
                printf("here are same queues\n");
                int isSame12 = isSame(queue1, queue2);
                int isSame13 = isSame(queue1, queue3);
                int isSame23 = isSame(queue2, queue3);

                if(isSame12 == isSame13 && isSame12 ==  1){printf("1, 2, 3\n");}
                else if(isSame12){printf("1, 2\n");}
                else if(isSame13){printf("1, 3\n");}
                else if(isSame23){printf("2, 3\n");}
                else{printf("There are no same queues:(\n");}
                break;
            case '5':
                while(queue1 != NULL)
                    pop(queue1);
                while(queue2 != NULL)
                    pop(queue2);
                while(queue3 != NULL)
                    pop(queue3);
                return;
            default:
                printf("There is no this case, try again\n");
                continue;
        }
    }

}