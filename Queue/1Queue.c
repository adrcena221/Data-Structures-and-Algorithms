#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueSLL.h"


int main(){
    int select, position, changeSelect;
    char name[50],number[20], browseSelect;
    struct Node *newNode;

    while(1)
    {
        
        printMenu();
        printf("\nYour Selection: ");
        scanf("%d", &select);
    
        if(select == 1)
        {
                printf("Enter your Name: ");
                scanf(" %[^\n]s", name);
                printf("Enter your Number: ");
                scanf(" %[^\n]s", number);
                newNode = createNode();
                assignNode(newNode, name, number);
                enQueue(&q, newNode);
        }

        else if(select == 2)
        {
                printList();
        }


        else if(select == 3)
        {
            printf("Deleted from the queue: %s\t\t|\t %s", deQueue());
        }

        else if(select == 4)
        {
            printf("Thank you for using! Goodbye!\n");
            break;
        }

    }
    return 0;
}