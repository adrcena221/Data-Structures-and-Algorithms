#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "QueueSLLCO1.h"

int main(){
    int select, position;
    char name[50],number[20], prescription[40], browseSelect;
    struct Node *newNode;
    struct Node *queue = NULL;
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
                printf("Prescription: ");
                scanf(" %[^\n]s", prescription);
                printf("Contact added to Phonebook!\n\n");
                newNode = createNode();
                assignNode(newNode, name, number, prescription);
                enQueue(&queue, newNode);
        }

        else if(select == 2)
        {
            printList(queue);
        }


        else if(select == 3)
        {
            deQueue(&queue, newNode);
            printf("\nFront is dequeued\n");
        }

        else if(select == 4)
        {
            printf("Goodbye have a nice day!\n");
            break;
        }

    }
    return 0;
}