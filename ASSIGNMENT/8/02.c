#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node* next;
};

struct List {
	struct node *front, *rear;
};

struct node* newNode(int k)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = k;
	temp->next = NULL;
	return temp;
}

struct List* createList()
{
	struct List* q = (struct List*)malloc(sizeof(struct List));
	q->front = q->rear = NULL;
	return q;
}

//*********************************************************************

void push_back(struct List* q, int k)
{
	struct node* temp = newNode(k);

	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	q->rear->next = temp;
	q->rear = temp;
    q->rear->next = q->front;
}


//*********************************************************************

void pop_front(struct List* q)
{
    struct node *head = q->front;
	struct node *previous = head, *firstNode = head;
 
    
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
 
   
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
        return;
    }
 
    while (previous->next != head) {
 
        previous = previous->next;
    }
 
    
    previous->next = firstNode->next;
 
    q->front = previous->next;
    free(firstNode);
    return;
}


//***********************************************************************

void printList(struct List *q) {
    struct node *ptr = q->front;

    if(q->front==NULL){printf("\nEmpty List\n"); return;}

    if(q->front==q->rear){
        printf("[ (%d) ]\n", ptr->key);
        return;
    }

    printf("\n[ ");
	
    do{

        printf("(%d) ",ptr->key);
        ptr = ptr->next;

    }while(ptr != q->front);
	
   printf(" ]\n");
}


//***********************************************************************
int length(struct List *q) {
    struct node *ptr = q->front;
    if(q->front==q->rear){return 1;}
    int ct=0;
    do{
        ptr = ptr->next;
        ct++;

    }while(ptr != q->front);
   return ct;
}
//***********************************************************************

void pop_back(struct List* q)
{
    struct node *head = q->front;
    struct node *current = head, *temp = head, *previous;
 
    if (head == NULL) {
        printf("\nList is empty\n");
        return;
    }
 
    if (q->front == q->rear) {
        q->front = NULL;
        q->rear = NULL;
        return;
    }
 
    while (current->next != head) {
        previous = current;
        current = current->next;
    }
 
    previous->next = current->next;
    q->front = previous->next;
    free(current);
    return;

}


//**********************************************************************

void push_front(struct List* q, int k)
{
    struct node *last = q->rear;
    struct node *first = q->front;
	if (q->front == NULL){
        push_back(q,k);
        return;
    } 

    struct node *temp = newNode(k);
    q->front = temp;
    temp->next = first;
    last->next = q->front;
    
}

//********************************************************************

void insertAt(struct List *q, int pos, int k){
    int len = length(q);

    if(pos<1 && pos>len+1){
        printf("\nEnter a valid position.\n");
        return;
    }

    if(pos==1){
        push_front(q, k);
    }

    else if(pos==len+1){
        push_back(q, k);
    }

    else
    {
        struct node* temp = newNode(k);
	    struct node* ptr = q->front ;
	    struct node* ptr2;
    
        int ct=2;
        while(ct!=pos){
            ptr = ptr->next;
            ct++;
        }

        ptr2 = ptr->next;
        ptr->next = temp;
        temp->next = ptr2;
    }

}

//***************************************************************

void deleteAt(struct List *q, int pos){
    int len = length(q);

    if(pos<1 && pos>len){
        printf("\nEnter a valid position.\n");
        return;
    }

    if(pos==1){
        pop_front(q);
    }

    else if(pos==len){
        pop_back(q);
    }

    else
    {
	    struct node* ptr1 = q->front;
	    struct node* ptr2 = q->front->next;
	    struct node* ptr3;
    
        int ct=2;
        while(ct!=pos){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ct++;
        }

        ptr3 = ptr2->next;
        ptr1->next = ptr3;
        free(ptr2);

    }

}

//***************************************************************

void Insert(struct List* q){
    printf("\nPress 1 to insert a element at the begining of the List.\n");
    printf("Press 2 to insert a element at the ending of the List.\n");
    printf("Press 3 to enter a element at a specified Postion.\n");
    int x; scanf("%d", &x);

    if(x==1){
        printf("\nEnter the Element you want to insert : ");
        int a; scanf("%d", &a);
        push_front(q, a);
    }

    else if(x==2){
        printf("\nEnter a Element you want to insert : ");
        int a; scanf("%d", &a);
        push_back(q, a);
    }

    else if(x==3){
        printf("\nEnter the Position And its Element : ");
        int a, b;
        scanf("%d %d", &a, &b);
        insertAt(q, a, b);
    }

    else{
        printf("Invalid Number.\n") ;
        return;
    }

}

void Delete(struct List *q){
    printf("\nPress 1 to delete a element at the begining of the List.\n");
    printf("Press 2 to delete a element at the ending of the List.\n");
    printf("Press 3 to delete a element at a specified Postion.\n");
    int x; scanf("%d", &x);

    if(x==1){pop_front(q);}

    else if(x==2){pop_back(q);}

    else if(x==3){
        printf("\nEnter the Position you want to remove : ");
        int a; scanf("%d", &a);
        deleteAt(q, a);
    }

    else{
        printf("Invalid Number.\n") ;
        return;
    }
}

int main()
{
    system("cls");
    struct List* list1 = createList();
	printf("This is a program to demonstrate Circular Linked List.\n");

    while(2>1)
    {
        printf("\nPress 1 to Insert a element in Circular Linked List.\n");
        printf("Press 2 to Delete a element in Circular Linked List.\n");
        printf("Press 3 to Display Circular Linked List.\n");
        printf("Press 4 to Exit Program.\n");

        int n; scanf("%d", &n);
        if(n==1){Insert(list1);}
        else if(n==2){Delete(list1);}
        else if(n==3){printList(list1);}
        else if(n==4){return 0;}
    
    }

}


