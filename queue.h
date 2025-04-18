//
// Created by intak on 16.04.2025.
//

#ifndef INC_6_QUEUE_H
#define INC_6_QUEUE_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* back;
} Queue;

typedef struct DequeNode {
    int data;
    struct DequeNode* next;
    struct DequeNode* prev;
} DequeNode;

typedef struct Deque {
    DequeNode* front;
    DequeNode* back;
} Deque;

#endif //INC_6_QUEUE_H
