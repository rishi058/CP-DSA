#include <stdio.h>
#include <stdlib.h>

struct student {char id[15]; char name[64]; int age;};

void getDetail(struct student *ptr) {

  for (int i = 0; i < 3; i++) {
    printf("Enter detail of student #%d\n", (i + 1));
    printf("Enter ID: ");
    scanf("%s", ptr->id);
    printf("Enter name: ");
    scanf("%s", ptr->name);
    printf("Enter age: ");
    scanf("%d", &ptr->age);
    
    // update pointer to point at next element
    // of the array std
    ptr++;
  }

}

void displayDetail(struct student *ptr) {

  for (int i = 0; i < 3; i++) {
    printf("\nDetail of student #%d\n", (i + 1));
    
    // display result via ptr variable
    printf("\nResult via ptr\n");
    printf("ID: %s\n", ptr->id);
    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);
    
    // update pointer to point at next element
    // of the array std
    ptr++;
  }

}

int main() {
  
  // student structure variable
  struct student std[3];
  
  // get student detail
  getDetail(std);
  
  // display student detail
  displayDetail(std);
  
  int tt; scanf("%d", &tt);

}


