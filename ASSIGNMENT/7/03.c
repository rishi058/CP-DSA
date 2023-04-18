#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/' || x == '%')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

//******************************************

int check(char exp[100]){
    int x=0,i=0;

    while(exp[i]!= '\0')  
    {  
        char c = exp[i];

        if(isalnum(c)==0 && c!='+' && c!='-' && c!= '/' 
          && c!='%' && c!='^' && c!='*' && c!=')' && c!='('){
              return -2;
          }

        if(exp[i]=='('){x++;}

        else if(exp[i]==')')  
        {  
            x--;     
            if(x<0)  
            break;  
        }  

        i++;
    }  
    if(x==0){ return 1;}    
    else { return -1 ;}  
    
}

//******************************************

int main()
{
    system("cls");
    char exp[100];
    char *e, x;
    printf("Enter the Infix expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;

    if(check(exp)==-1){
        printf("Expression is not balanced.");
        return 0;
    }

    else if(check(exp)==-2){
        printf("Invalid Arguments.");
        return 0;
    }

    printf("%d", check(exp));
    
   printf("Obtained Postfix expression : ");

    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    

    while(top != -1)
    {
        printf("%c ",pop());
    }
    
    printf("\n\n");
    return 0;

}

