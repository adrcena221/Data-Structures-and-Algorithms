struct Node
{    
    char data[50], data2[20], data3[50];
    int contents[5];
    struct Node* next;

    struct Node* front;
    struct Node* rear;

    int priority;
    
};

void printMenu()
{
    printf("***Phonebook***\n\n");
    printf("1. Append \n");
    printf("2. Browse \n");;
    printf("3. Delete \n");
    printf("4. Exit \n");
}

struct Node* createNode()
{
    struct Node *new;
    new = malloc(sizeof(struct Node));
    return new;
}

void assignNode(struct Node* newNode, char name[], char number[], char prescription[])
{
    strcpy(newNode -> data, name);
    strcpy(newNode -> data2, number);
    strcpy(newNode -> data3, prescription);
    newNode -> next = NULL;
}

void enQueue(struct Node** queue, struct Node* newNode)
{
    struct Node *ptr;
    ptr = *queue;

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
    for (p = queue; p; p = p->front) 
    {
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