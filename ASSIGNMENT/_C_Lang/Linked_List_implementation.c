// A C program to demonstrate linked list based implementation of queue
#include <stdio.h>
#include <stdlib.h>


//**********************************************************************************************************
// A linked list (LL) node to store a queue entry
struct node {
	int key;
	struct node* next;
};

// The queue, front stores the front node of LL and rear stores the
// last node of LL
struct List {
	struct node *front, *rear;
};

// A utility function to create a new linked list node.
struct node* newNode(int k)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

// A utility function to create an empty queue
struct List* createList()
{
	struct List* q = (struct List*)malloc(sizeof(struct List));
	q->front = q->rear = NULL;
	return q;
}

//************************************************************************************************************8

// The function to add a key k to q
void push_back(struct List* q, int k)
{
	// Create a new LL node
	struct node* temp = newNode(k);

	// If queue is empty, then new node is front and rear both
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	// Add the new node at the end of queue and change rear
	q->rear->next = temp;
	q->rear = temp;
}


//********************************************************************************************************************
// Function to remove a key from given queue q
void pop_front(struct List* q)
{
	// If queue is empty, return NULL.
	if (q->front == NULL)
		return;

	// Store previous front and move front one node ahead
	struct node* temp = q->front;

	q->front = q->front->next;

	// If front becomes NULL, then change rear also as NULL
	if (q->front == NULL)
		q->rear = NULL;

	free(temp);
}


//*********************************************************************************************************************

void printList(struct List *q) {
   struct node *ptr = q->front;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d) ",ptr->key);
      ptr = ptr->next;
   }
	
   printf(" ]");
}


//*************************************************************************************************************************
int length(struct List *q) {
  struct node *ptr = q->front;
  
  int ct=0;
   while(ptr != NULL) {
      ct++;
      ptr = ptr->next;
   }
   return ct;
}
//*************************************************************************************************************************

void pop_back(struct List* q)
{
    struct node *ptr1 = q->front;
    struct node *ptr2 = q->front->next;

    while(0<8) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        if(ptr2->next == NULL){
            ptr1->next = NULL;
            q->rear = ptr1;
            free(ptr2);
            break;
        }
    }

}


//*************************************************************************************************************************

void push_front(struct List* q, int k)
{
	// Create a new LL node
	struct node* temp = newNode(k);
	struct node* temp2;

	// Add the new node at the end of queue and change rear
	temp2 = q->front;
	q->front = temp;

	temp->next = temp2;
    
}

//*************************************************************************************************************************

int find(struct List *q, int k){
struct node *ptr = q->front;
  
  int ct=0;
   while(ptr != NULL) {
      ct++;
      if(ptr->key == k){break;}
      ptr = ptr->next;
   }
   return ct;
}

//*************************************************************************************************************************


/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
    int temp = a->key;
    a->key = b->key;
    b->key = temp;
}


void bubbleSort(struct List *q)
{
	struct node *start = q->front;
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->key > ptr1->next->key)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

//*************************************************************************************************************************
void reverseList(struct List *q) {

    struct node *head = q->front;
    struct node *prev = NULL, *cur=head, *tmp;

    while(cur){
        tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }

    q->rear = head;
    q->front = prev;
    
}

//*************************************************************************************************************************

void addList(struct List *q1, struct List *q2){

    q1->rear->next = q2->front;

}

//*************************************************************************************************************************


// Driver Program to test anove functions
int main()
{
	struct List* list1 = createList();
	struct List* list2 = createList();


	//struct Queue* list2 = createList();

	push_back(list1, 3);
	push_back(list1, 4);
	push_back(list1, 5);
	push_back(list1, 6);
    //append(list1, 1);
    pop_front(list1);
    push_front(list1, 1);

    push_back(list2, 13);
	push_back(list2, 4);
	push_back(list2, 51);
	push_back(list2, 16);
    pop_back(list2);
    push_back(list2, 88);
	bubbleSort(list2);
	// reverseList(list2);

    int l = length(list2);
    printf("\n%d\n", l);

    // struct node *
    // insertAfter(14, 11);


	
	printf("List.begin() : %d \n", list1->front->key);
	printf("List.end() : %d \n", list1->rear->key);
    printList(list1);
    reverseList(list2);
    addList(list1, list2);
    printList(list2);

	// printf("Queue Rear : %d", pp->rear->key);
	return 0;
}


