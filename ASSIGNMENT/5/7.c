#include<stdio.h>
#include<stdlib.h>

struct cricketers{ char name[100]; int runs; int wickets;} temp;

int main(){
    system("cls");
    printf("Enter the no. of players : ");
    int n; scanf("%d", &n );

    struct cricketers players[n];

    for(int i=0; i<n; i++){
        printf("\nEnter the name of player%d : ", i);
        char n[100]; scanf("%s", &n);
        strcpy(players[i].name,n);

        printf("Enter the runs scored by player%d : ", i);
        int r; scanf("%d", &r);
        players[i].runs = r;

        printf("Enter the wickets taken by player%d : ", i);
        int j; scanf("%d", &j);
        players[i].wickets = j;

    }

    printf("\nList of players information after sorting thier runs : \n");

    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++) {
            if (players[j].runs<players[j+1].runs) {
                temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
   

    for(int i = 0; i < n; i++) {
        printf("Name = %s, Runs scored = %d, Wickets Taken = %d \n", players[i].name, players[i].runs , players[i].wickets);
    }
    int tt; scanf("%d", &tt);

}