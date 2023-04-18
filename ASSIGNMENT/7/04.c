#include <stdio.h>
#include <stdlib.h>

struct MyQueue
{
	int data;
	struct MyQueue *next;
};
struct MyStack
{
	struct MyQueue *element;
	struct MyStack *next;
};

struct MyQueue *head = NULL, *tail = NULL;
struct MyStack *top = NULL;

void enqueue(int value)
{
	struct MyQueue *node = (struct MyQueue *) malloc(sizeof(struct MyQueue));
	if (node == NULL)
	{
		printf("Memory overflow\n");
	}
	else
	{
		node->data = value;
		node->next = NULL;
		if (head == NULL)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}
}

int dequeue()
{
	int data = -1;
	if (head == NULL)
	{
		printf("Empty Queue\n");
		return data;
	}
	struct MyQueue *temp = head;
	data = temp->data;
	head = head->next;
	if (head == NULL)
	{
		tail = NULL;
	}
	free(temp);
	temp = NULL;
	return data;
}

void push(struct MyQueue *node)
{
	struct MyStack *new_node = (struct MyStack *) malloc(sizeof(struct MyStack));
	if (new_node)
	{
		new_node->element = node;
		new_node->next = top;
		top = new_node;
	}
}

struct MyQueue *pop()
{
	if (top != NULL)
	{
		struct MyQueue *result = top->element;
		struct MyStack *temp = top;
		top->element = NULL;
		top = top->next;
		free(temp);
		temp = NULL;
		return result;
	}
	return NULL;
}


void print_queue()
{
	struct MyQueue *temp = head;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void reverse()
{
	struct MyQueue *temp = head;

	while (head != NULL)
	{
		temp = head;
		push(head);
		head = head->next;
		temp->next = NULL;
	}

	while (top != NULL)
	{
		if (head == NULL)
		{
			head = pop();
			tail = head;
		}
		else
		{
			tail->next = pop();
			tail = tail->next;
		}
	}
}
int main()
{
	printf("Enter the number of elements you want to insert in queue : ");
	int n; scanf("%d", &n);

	printf("\nEnter the Elements you want to insert : ");

	for(int i=0; i<n; i++){
		int x; scanf("%d", &x);
		enqueue(x);
	}
	
  	printf("Before : ");
	print_queue();
	reverse();
  	printf("After : ");
	print_queue();5
	return 0;
}