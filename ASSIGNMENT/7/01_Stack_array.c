#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

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

int isFull(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
	if (isFull(stack)){printf("OVER_FLOW\n");}
	else{
		stack->array[++stack->top] = item;
		printf("Pushed into Stack -> %d\n", item);
	}
}

void pop(struct Stack* stack)
{
	if (!isEmpty(stack)){
		stack->array[stack->top--]; 
		printf("Element Popped !\n");
	}
	else {printf("UNDER_FLOW\n");}
}

int peek(struct Stack* stack)
{
	if (isEmpty(stack)){printf("\nStack is empty\n");}
	else {
		return stack->array[stack->top];
	}
}

void display(struct Stack* stack){
	if (isEmpty(stack)){printf("\nStack is empty\n"); return;}
	else
	{
		printf("Current Stack -> ");
		for(int i=0; i<stack->capacity; i++){
			printf(" %d ", stack->array[i]);
			if(stack->array[i]==stack->array[stack->top]){break;}
		}
	}

}

bool ispal(char arr[], int size){
	struct Stack* stack = createStack(size/2);
	bool flag = true;

	for(int i = 0; i<(size/2); i++){
		push(stack, arr[i]);
	}

	int k ;
	if(size%2==1){k = (size/2) + 1;}
	else {k = size/2;}

	for(int i = k; i<size ; i++){
		int z = peek(stack);
		if(z!=arr[i]){flag = false; break;}
		pop(stack);
	}

	return flag ;

}

void pal(){

    printf("Enter size of Array for which you want to check palindrome\n");

	int n; scanf("%d", &n);
    char s[n];

    printf("Now start entering elements:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &s[i]);
    }

    if(ispal(s,n)){
        printf("Yes it is.\n\n");
    }
	else{
        printf("No its not!!\n\n");
    }
}


int main()
{
	system("cls");

	printf("Enter the Size of Stack : ");
	int x; scanf("%d", &x);

	struct Stack* stack = createStack(x);

	while(2<5){
    printf("\n\nPress 1 to push a element in Stack : ");
    printf("\nPress 2 to pop a element in Stack : ");
    printf("\nPress 3 to diplay Stack : ");
    printf("\nPress 4 to Peek into Stack : ");
    printf("\nPress 5 to check for palindrome using Stack : ");
    printf("\nPress 6 to Exit : \n\n");

    int n; scanf("%d", &n);
	
    if(n==1){
      printf("Enter the element you want to insert : ");
      int k; scanf("%d", &k);
      push(stack, k);
    }

    if(n==2){
      pop(stack);
    }

    else if(n==3){
      display(stack);
    }

    else if(n==4){
      printf("Top -> %d", peek(stack));
    }

	else if(n==5){
      pal();
    }

    else if(n==6){
      printf("Exited. ");
      return 0;
    }

  }
	return 0;
}
