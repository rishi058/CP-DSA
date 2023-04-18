// C program for array implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
struct Stack {
	int top;
	unsigned capacity;
	int* array;
};

// function to create a stack of given capacity. It initializes size of
// stack as 0
struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

// Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

// Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item)
{
	if (isFull(stack)){printf("OVER_FLOW\n"); return;}

	stack->array[++stack->top] = item;
}

// Function to remove an item from stack. It decreases top by 1
void pop(struct Stack* stack)
{
	if (!isEmpty(stack)){stack->array[stack->top--];}
	else {printf("UNDER_FLOW\n");}
}

// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
	if (isEmpty(stack))
		return INT_MIN;

	return stack->array[stack->top];
}

//***************************
void print(){
    // make a copy of stack and peek & pop until empty
}

//****************************

// Driver program to test above functions
int main()
{
	struct Stack* stack = createStack(100);

	push(stack, 10);
	push(stack, 20);
	push(stack, 30);

	pop(stack);
	pop(stack);
	push(stack, 310);
	pop(stack);


    printf("%d", peek(stack));
    

	return 0;
}

/*
Pros: Easy to implement. Memory is saved as pointers are not involved. 
Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.
*/