#include<stdio.h>

int main(){

    printf("Enter two strings : ");
    char string[100]; 
    char string2[100]; 
    gets(string);
    int j=0;
    for(int i=0; i<100; i++){
        if(string[i]==' '){continue;}
        else{ string2[j]=string[i]; j++;}
    }
    printf("\nConcatenated string : %s", string2);
    int tt; scanf("%d", &tt);

}