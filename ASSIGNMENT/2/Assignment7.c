#include<stdio.h>

int main()
{
    int distance;
    float time, velocity;
    printf("Enter the distance travelled by the vehicle(in meters) :  ");
    scanf("%d", &distance);
    printf("\nEnter the time taken by the vehicle to travel(in seconds) : ");
    scanf("%f", &time);
    
    velocity = distance/time;
    printf("\nThe velocity of the vehicle(in m/s) is : %.2f", velocity);

    int i;
    scanf("%d", i);
    return 0;
}
