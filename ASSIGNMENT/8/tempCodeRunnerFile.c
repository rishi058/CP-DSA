#include <stdio.h>
#include <stdlib.h>

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

// A utility function to create an empty List
struct List* createList()
{
	struct List* q = (struct List*)malloc(sizeof(struct List));
	q->front = q->rear = NULL;
	return q;
}

//*********************************************************************

// The function to add a key k to q
void push_back(struct List* q, int k)
{
	// Create a new LL node
	struct node* temp = newNode(k);

	// If List is empty, then new node is front and rear both
	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}

	// Add the new node at the end of queue and change rear
	q->rear->next = temp;
	q->rear = temp;
}


//*********************************************************************

// Function to remove a key from given List q
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


//***********************************************************************

void printList(struct List *q) {
   struct node *ptr = q->front;
   printf("\n[ ");
	
   //start from the beginning
   while(ptr != NULL) {
      printf("(%d) ",ptr->key);
      ptr = ptr->next;
   }
	
   printf(" ]\n");
}


//***********************************************************************
int length(struct List *q) {
  struct node *ptr = q->front;
  
  int ct=0;
   while(ptr != NULL) {
      ct++;
      ptr = ptr->next;
   }
   return ct;
}
//***********************************************************************

void pop_back(struct List* q)
{
    struct node *ptr1 = q->front;
    struct node *ptr2 = q->front->next;
    if(ptr2==q->rear){
        free(ptr1);
        q->front = ptr2;
        return;
    }
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


//**********************************************************************

void push_front(struct List* q, int k)
{
	// Create a new LL node
	struct node* temp = newNode(k);
	struct node* temp2;

	// Add the new node at the end of queue and change rear
    if (q->front == NULL) {
		q->front = q->rear = temp;
		return;
	}

	temp2 = q->front;
	q->front = temp;

	temp->next = temp2;
    
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
    
        int ct=0;
        while(ct!=pos-2){
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
        printf("\nEnter the Position And its Elemnet : ");
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
	printf("This is a program to demonstrate Linked List.\n\n");

    while(2>1)
    {
        printf("Press 1 to Insert a element in Linked List.\n");
        printf("Press 2 to Delete a element in Linked List.\n");
        printf("Press 3 to Display Linked List.\n");
        printf("Press 4 to Exit Program.\n");

        int n; scanf("%d", &n);
        if(n==1){Insert(list1);}
        else if(n==2){Delete(list1);}
        else if(n==3){printList(list1);}
        else if(n==4){return 0;}
    
    }

}


