//
// Created by andrei ivashneu on 16.04.2025.
//

#include "functions.h"
void setNumber(int* number)
{
    int inputValid;
    do{
        *number = 0;
        int digit;
        inputValid = 1;
        int isNegative = 1, isEmpty = 1;

        while ((digit = getchar()) != '\n' && digit != ' ') {
            if(digit == '-' && *number == 0) {
                isNegative = -1;
            }
            else if (digit < '0' || digit > '9') {
                printf("Incorrect input. Only digits are allowed.\n");
                inputValid = 0;
                while ((digit = getchar()) != '\n' && digit != ' ');
                break;
            }
            else {
                if (*number > (INT_MAX - (digit - '0')) / 10) {
                    printf("Number is too large. Maximum value is %d.\n", INT_MAX);
                    inputValid = 0;
                    while ((digit = getchar()) != '\n' && digit != ' ');
                    break;
                }
                isEmpty = 0;
                *number = *number * 10 + (digit - '0');
            }
        }

        if (isEmpty){
            printf("Empty enter\n");
            inputValid = 0;
        }

        if (!inputValid)
            *number = 0;

        if (digit != '\n'){
            printf("You need to write only one number\n");
            inputValid = 0;
            while ((digit = getchar()) != '\n');
        }


        *number *=isNegative;

    }while(inputValid == 0);
}
int getAnswer()
{
    printf("\nYES - 1, NO - 0\n");
    int ch = getch();
    if(ch == '1'){return 1;}
    if(ch == '0'){return 0;}
}
int max(int first, int second)
{
    return first > second ? first : second;
}
int min(int first, int second)
{
    return first < second ? first : second;
}
int isEmpty(Queue* q) {
    return q->front == NULL;
}
Queue* createQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->back = NULL;
    return q;
}

void push(Queue* queue, int value, int maxSize)
{
    if(sizeQueue(queue) == maxSize){
        printf("you cant add more elements\n");
        return;
    }
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("malloc failed.\n");
        return;
    }

    temp->data = value;
    temp->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->back = temp;
    }
    else{
        queue->back->next = temp;
        queue->back = temp;
    }
}
int pop(Queue *queue)
{
    if(queue == NULL)
    {
        printf("queue is empty\n");
        return 0;
    }
    Node *temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;
    if(queue->front == NULL)
    {
        queue->back = NULL;
    }
    free(temp);
    return value;
}
void show(Queue* queue)
{
    Node* temp = queue->front;
    printf("Queue: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int showToFirstNegative(Queue* queue)
{
    int last = 0, isWasNegative = 0;
    Node* temp = queue->front;
    printf("Queue: ");
    while(temp != NULL )
    {
        last += isWasNegative;
        if(!isWasNegative)
            printf("%d, ", temp->data);
        if(temp->data < 0){isWasNegative = 1;}
        temp = temp->next;
    }
    printf("\n");
    return last;
}
int sizeQueue(Queue* queue)
{
    int size = 0;
    Node* temp = queue->front;
    while(temp!=NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

Deque* createDeque()
{
    Deque* d = (Deque*)malloc(sizeof(Deque));
    d->front = d->back = NULL;
    return d;
}
void push_back(Deque* deque, int value, int maxSize)
{
    if(sizeDeque(deque) == maxSize){
        printf("you cant add more elements\n");
        return;
    }
    DequeNode* temp = (DequeNode*)malloc(sizeof(DequeNode));
    if(temp == NULL){
        printf("malloc error\n");
        return;
    }
    temp->data = value;
    temp->next = NULL;
    temp->prev = deque->back;

    if (deque->front == NULL) {
        deque->front = deque->back = temp;
    }
    else{
        deque->back->next = temp;
        deque->back = temp;
    }
}
void push_front(Deque* deque, int value, int maxSize)
{
    if(sizeDeque(deque) == maxSize){
        printf("you cant add more elements\n");
        return;
    }
    DequeNode* temp = (DequeNode*)malloc(sizeof(DequeNode));
    if(temp == NULL){
        printf("malloc error\n");
        return;
    }

    temp->data = value;
    temp->next = deque->front;
    temp->prev = NULL;

    if (deque->back == NULL) {
        deque->back = deque->front = temp;
    }
    else{
        deque->front->prev = temp;
        deque->front = temp;
    }
}
int pop_back(Deque* deque)
{
    if(sizeDeque(deque) == 0){return -1;}

    DequeNode* temp = deque->back;
    int value = temp->data;

    deque->back = deque->back->prev;
    if(deque->back == NULL){
        deque->front = NULL;
    }
    else{
        deque->back->next = NULL;
    }
    free(temp);
    return value;
}
int pop_front(Deque* deque)
{
    if(sizeDeque(deque) == 0){return -1;}

    DequeNode* temp = deque->front;
    int value = temp->data;

    deque->front = deque->back->next;
    if(deque->front == NULL){
        deque->back = NULL;
    }
    else{
        deque->front->prev = NULL;
    }
    free(temp);
    return value;
}
int sizeDeque(Deque* deque)
{
    int size = 0;
    DequeNode* temp = deque->front;
    while(temp!=NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
void showDeque(Deque* deque)
{
    DequeNode* temp = deque->front;
    printf("Deque: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int showToFirstNegativeInDeque(Deque* deque)
{
    int last = 0, isWasNegative = 0;
    DequeNode* temp = deque->back;
    printf("Deque: ");
    while(temp != NULL )
    {
        last += isWasNegative;
        if(!isWasNegative)
            printf("%d, ", temp->data);
        if(temp->data < 0){isWasNegative = 1;}
        temp = temp->prev;
    }
    printf("\n");
    return last;
}