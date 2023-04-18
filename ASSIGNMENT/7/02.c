#include <stdio.h>
#define SIZE 4

int items[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue(int element) {
  if (isFull())
    printf("\nQueue is full!! __ OVERFLOW...\n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("\nInserted -> %d", element);
  }
}

// Removing an element
int deQueue() {
  int element;
  if (isEmpty()) {
    printf("\nQueue is empty !!  __ UNDERFLOW...\n");
    return (-1);
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
    return (element);
  }
}

// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\nItems -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    // printf("\n Rear -> %d \n", rear);
  }
}

void status(){
  printf("Front -> %d", front);
}

int main() {

  system("cls");

  printf("Size of Queue = 4 \n\n");

  while(2<5){
    printf("\nPress 1 to insert a element in Queue : ");
    printf("\nPress 2 to delete a element in Queue : ");
    printf("\nPress 3 to diplay Queue : ");
    printf("\nPress 4 to check status of Queue : ");
    printf("\nPress 5 to Exit : \n\n");

    int n; scanf("%d", &n);
    if(n==1){
      printf("Enter the element you want to insert : ");
      int k; scanf("%d", &k);
      enQueue(k);
    }

    if(n==2){
      deQueue();
    }

    else if(n==3){
      display();
    }

    else if(n==4){
      status();
    }

    else if(n==5){
      printf("Exited. ");
      return 0;
    }

  }

  return 0;
}