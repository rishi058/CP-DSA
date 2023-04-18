// A C program to demonstrate linked list based implementation of sueue
#include <stdio.h>
#include <stdlib.h>


//**********************************************************************************************************
// A linked list (LL) node to store a sueue entry
struct node {
	int key;
	struct node* next;
};

// The sueue, top stores the top node of LL and rear stores the
// last node of LL
struct Stack {
	struct node *top;
};

// A utility function to create a new linked list node.
struct node* newNode(int k)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

// A utility function to create an empty sueue
struct Stack* createStack()
{
	struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
	s->top = NULL;
	return s;
}

//************************************************************************************************************8

void push(struct Stack* q, int k)
{
	// Create a new LL node
	struct node* temp = newNode(k);
	struct node* temp2;

	// Add the new node at the end of queue and change rear
	temp2 = q->top;
	q->top = temp;

	temp->next = temp2;
    
}

//*********************************************************************************************************************

void printStack(struct Stack *s) {
   struct node *ptr = s->top;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d) ",ptr->key);
      ptr = ptr->next;
   }
	
   printf(" ]");
}


//*************************************************************************************************************************
int length(struct Stack *s) {
  struct node *ptr = s->top;
  
  int ct=0;
   while(ptr != NULL) {
      ct++;
      ptr = ptr->next;
   }
   return ct;
}
//*************************************************************************************************************************

void pop(struct Stack* s)
{
    struct node *ptr1 = s->top;
    struct node *ptr2 = s->top->next;

    s->top = ptr2;
	free(ptr1);

}


//*************************************************************************************************************************

int top(struct Stack *s){
	return s->top->key;
}


//*************************************************************************************************************************


// Driver Program to test anove functions
int main()
{
	struct Stack* stack1 = createStack();
	struct Stack* stack2 = createStack();


	//struct Queue* list2 = createStac
	push(stack1, 3);
	push(stack1, 4);
	push(stack1, 5);
	push(stack1, 6);

	pop(stack1);

	printf("%d\n", length(stack1));

	int x = top(stack1);

	printf("%d\n", x);
    


	
	printf("Stack.top() : %d \n", stack1->top->key);
    printStack(stack1);

	// printf("Queue Rear : %d", pp->rear->key);
	return 0;
}


