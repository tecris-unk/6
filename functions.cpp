//
// Created by intak on 16.04.2025.
//

#include "functions.h"
#include "functions.h"
void setNumber(int* number)
{
    rewind(stdin);
    *number = 0;
    int digit;
    while((digit = getchar()) != '\n' && digit != ' ')
    {
        if(digit < '0' || digit > '9'){
            printf("Incorrect number\n");
            while((digit = getchar()) != '\n' && digit != ' ');
            *number = 0;
        }
        else{*number = *number * 10 + digit - '0';}
    }
    rewind(stdin);
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

Queue* push(Stack* top, int data, int *size, int maxSize)
{

}
Stack* pop(Stack* top)
{
    if(top == NULL){return top;}
    Stack* next = top->next;
    free(top);
    return next;
}
void show(Stack* top)
{
    if(top == NULL){return;}
    printf("%d\n", top->data);
    show(top->next);
}