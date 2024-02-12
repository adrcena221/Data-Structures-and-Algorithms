struct Node
{    
    char data[50], data2[20];
    struct Node* next;
    struct Node* prev;

    struct Node* front;
    struct Node* rear;
};

void printMenu()
{
    printf("***Phonebook***\n\n");
    printf("1. Append \n");
    printf("2. Browse \n");;
    printf("3. Delete \n");
    printf("4. Exit \n");
}

void browse()
{
    printf("\na. Traverse\n");
    printf("b. Reverse List\n");
    printf("\nSelect browsing: ");
}

struct Node* createNode()
{
    struct Node *new;
    new = malloc(sizeof(struct Node));
    return new;
}

void assignNode(struct Node* newNode, char name[], char number[])
{
    strcpy(newNode -> data, name);
    strcpy(newNode -> data2, number);
    newNode -> next = NULL;
}

void enQueue(struct Node** queue, struct Node* newNode)
{
    struct Node *ptr;
    ptr = *queue;
    newNode -> prev = NULL;
    if(*queue == NULL)
    {
        newNode -> front = *queue;
        *queue = newNode;
    }
    else
    {

        newNode -> front = NULL;
        while(ptr->front !=NULL)
            ptr = ptr -> front;
        ptr -> front = newNode;

        (*queue) -> prev = newNode;
    }
    
}

void deQueue(struct Node **queue, struct Node* newNode)
{
    struct Node* ptr;
    ptr = *queue;
    if (*queue ==NULL)
    {
        printf("Queue is empty!\n");
    }
    *queue = ptr -> front;
    free(ptr);
    ptr = *queue;
}


void printList(struct Node* queue) 
{
    struct Node* p;
    int count = 1;
    for (p = queue; p; p = p->front) {
        printf("%d.) ", count);
        count++;
        printf("%s\t--->\t %s", p -> data, p -> data2);
        printf("\n");
    }
    if(queue == NULL)
    {
        printf("\nYour Phonebook is Empty!");
    }
    printf("\n");
}

void printReverse(struct Node** queue)
{
    if(*queue == NULL)
        printf("\n\nERROR: No records available.\n\n");
    else
    {
        printf("\n***Phonebook***\n");
        struct Node *ptr = malloc(sizeof(struct Node));
        ptr = *queue;
        while(ptr->front != NULL)
            ptr = ptr->front;
        while(ptr != NULL)
        {
            printf("%s\t\t|\t %s\n", ptr -> data, ptr -> data2);
            ptr = ptr->prev;
        }
        printf("\n");
    }
}