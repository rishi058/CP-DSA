#include <bits/stdc++.h>

#include "turtle.c"

using namespace std;


int main(){

    turtle_init(900, 900);          // initialize the image to be 600x600

    turtle_forward(400);
    turtle_turn_left(90);
    turtle_forward(400);
    turtle_draw_turtle();

    turtle_save_bmp("output.bmp");  // save the turtle drawing

    int t; cin>>t;
}
