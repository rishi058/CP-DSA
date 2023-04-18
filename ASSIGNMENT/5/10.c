#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(char str[])
{
    int n = strlen(str);
    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(str[i]>str[j]){
                char a= str[i];
                str[i]=str[j];
                str[j]=a;
            }
        }
    }
}

int main(){
    printf("Enter a string : ");
    char string1[100];
    scanf("%s", &string1);
   
   sort(string1);

   printf("Sorted string : %s", string1);
    int tt; scanf("%d", &tt);

}