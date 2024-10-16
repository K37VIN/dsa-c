#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (front == (rear + 1) % MAX);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
    } else {
        if (isEmpty()) {
            front = rear = 0;  
        } else {
            rear = (rear + 1) % MAX;  
        }
        queue[rear] = value;
        printf("Enqueued %d to the queue.\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        printf("Dequeued %d from the queue.\n", queue[front]);
        if (front == rear) {
            front = rear = -1;  
        } else {
            front = (front + 1) % MAX;  
        }
    }
}

void traverse() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) break;
            i = (i + 1) % MAX; 
        }
        printf("\n");
    }
}

int numberOfElements() {
    if (isEmpty()) {
        return 0;
    }
    if (rear >= front) {
        return rear - front + 1;
    } else {
        return (MAX - front) + (rear + 1);
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Check if Queue is Full\n");
        printf("6. Number of Elements in Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traverse();
                break;
            case 4:
                if (isEmpty())
                    printf("Queue is empty.\n");
                else
                    printf("Queue is not empty.\n");
                break;
            case 5:
                if (isFull())
                    printf("Queue is full.\n");
                else
                    printf("Queue is not full.\n");
                break;
            case 6:
                printf("Number of elements in queue: %d\n", numberOfElements());
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}