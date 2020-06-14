#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
}*front = NULL,*rear = NULL;

void insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = NULL;
    if(front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
    printf("Insertion is Success!!!\n");
}

void delete()
{
    if(front == NULL)
    {
        printf("Queue is Empty!!!\n");
    }
    else
    {
        struct Node *temp = front;
        front = front -> next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}

void display()
{
    if(front == NULL)
    {
        printf("Queue is Empty!!!\n");
    }
    else
    {
        struct Node *temp = front;
        while(temp->next != NULL)
        {
            printf("%d--->",temp->data);
            temp = temp -> next;
        }
        printf("%d--->NULL\n",temp->data);
    }
}

void main()
{
    int choice, value;
    while(1)
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the value to be insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
}