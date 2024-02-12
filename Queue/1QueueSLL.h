struct Node{
    char data[50], data2[20];

    struct Node* next;

};

struct Node *front = NULL;
struct Node *rear = NULL;

void printMenu()
{
    printf("Phonebook\n\n");
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

void assignNode(struct Node* newNode, char name[], char number[])
{
    strcpy(newNode -> data, name);
    strcpy(newNode -> data2, number);
    newNode -> next = NULL;

}

void enQueue(struct Node** q, struct Node* newNode)
{
    newNode -> next = *q;
    (*q) = newNode;
    struct Node *ptr;
	ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = newNode;
	ptr->next = NULL;
	if ((front == NULL) && (rear == NULL)) {
		front = rear = ptr;
	}
	else{
		rear->next = ptr;
		rear = ptr;
	}
	printf("Node is Inserted\n\n");
}

int deQueue()
{
    if (front == NULL) 
    {
		printf("\nUnderflow\n");
               return -1;
	}
	else 
    {
		struct Node* temp = front;
		int temp_data = front->data;
		front = front->next;
		free(temp);
		return temp_data;
	}
}

void printList() 
{
	struct Node *temp;
	if ((front == NULL) && (rear == NULL)) 
    {
		printf("\nYour Phone Book is empty.\n");
	}

	else 
    {
		struct Node* temp;
        int count = 1;

        for (p = temp; p; p = p->next) 
        {
        printf("%d.) ", count);
        count++;
		temp = front;
		while (temp) 
        {
			printf("%s\t\t|\t %s", temp -> data, temp -> data2);
			temp = temp->next;
		}
		printf("NULL\n\n");
	    }
    }
}
