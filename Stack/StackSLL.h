struct Node{
    char data[50], data2[20];

    struct Node* next;

};

void printMenu()
{
    printf("Phonebook\n\n");
    printf("1. Append \n");
    printf("2. Browse \n");;
    printf("3. Delete \n");
    printf("4. Exit \n");
}

void selectBrowse()
{
    printf("\na. Traverse\n");
    printf("b. Element on Top \n");
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

void push(struct Node** stack, struct Node* newNode)
{
    newNode -> next = *stack;
    (*stack) = newNode;
}

void pop(struct Node** stack)
{
    if (*stack != NULL)
    {
        printf("Element popped: %s\t\t|\t %s\n\n", (*stack) -> data, (*stack) -> data2);
        struct Node* tempPtr = *stack;
        *stack = (*stack) -> next;
        free(tempPtr);
    }
    else
    {
        printf("\nThe list is empty.\n");
    }


}

void top(struct Node* stack)
{

    if (stack != NULL)
    {
        printf("Element on top: %s\t\t|\t %s\n\n", stack -> data, stack -> data2);
    }
    else
    {
        printf("\nThe stack is empty.\n");
    }
}

void printList(struct Node* stack) {
    struct Node* p;
    int count = 1;
    for (p = stack; p; p = p->next) {
        printf("%d.) ", count);
        count++;
        printf("%s\t\t|\t %s", p -> data, p -> data2);
        printf("\n");
    }
    if(stack == NULL)
    {
        printf("\nYour Phone Book is empty.");
    }
    printf("\n");
}
