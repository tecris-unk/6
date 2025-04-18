//
// Created by andrei ivashneu on 16.04.2025.
//


#include "functions.h"


int main(void) {
    while(1)
    {
        printf("Enter task number: ");
        int choice = getch();
        system("cls");
        switch(choice)
        {
            case '1':
                createAndShowQueue();
                break;
            case '2':
                createAndShowDeque();
                break;
            case '3':
                FindSameQueues();
                break;
            default:
                printf("There is no this task, try again\n");
                continue;
        }
        printf("Do you want to continue? ");
        if(!getAnswer()){return 0;}
        system("cls");
    }
}
