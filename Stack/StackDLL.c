#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackDLL.h"


int main(){
    int select, position, changeSelect;
    char name[50],number[20], browseSelect;
    struct Node *newNode;
    struct Node *stack = NULL;
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
                push(&stack, newNode);
        }

        else if(select == 2)
        {
            selectBrowse();
            scanf(" %c", &browseSelect);
            if (browseSelect == 'a')
            {
                printList(stack);
            }
            else if (browseSelect == 'b')
            {
                top(stack);
            }
            else if (browseSelect == 'c')
            {
                printListReverse(&stack);
            }
            
        }

        else if(select == 3)
        {
            pop(&stack);
        }

        else if(select == 4)
        {
            printf("Thank you for using! Goodbye!\n");
            break;
        }

    }
    return 0;
}