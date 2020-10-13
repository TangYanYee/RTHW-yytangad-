#include <stdio.h>
#include <math.h>
int maxd1 = 0;
int maxd = 0;

int max_distance(int seats[], int length) {
  for(int i =0; i<=length ; i++){
    if (seats[i] == 0){
      //calculate no. of unoccupied seats
      maxd++;
    }else{
      if (maxd >= maxd1){
        //comapare the no. of seats to find the max no.
        maxd1 = maxd;
      }
      maxd = 0;
    }
  }
    //printf("maxd1: %d\n", maxd1);
    return ceil(maxd1*0.5);
}

int main() {
    int seats[] = {1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0};
    int length = sizeof(seats) / sizeof(seats[0]);
    printf("max_distance = %d", max_distance(seats, length));
    return 0;
}