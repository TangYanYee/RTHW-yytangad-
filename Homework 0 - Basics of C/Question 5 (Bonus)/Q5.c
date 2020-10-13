#include <stdio.h>
int maxd1 = 0;
int maxd = 0;
int seat1 = 0;
int seatinf = 0;
int first = 0;

int max_distance(int seats[], int length) {
  for(int i =0; i<length ; i++){
    if (seats[i] == 0){
      maxd++;
      //printf("hello\n");
    }if(seats[length-1]==0){
      seatinf = maxd;
    }
    if (seats[i] == 1){
      if(seats[0]== 0 && first == 0){
        seat1 = maxd;
        first++;
      }if (maxd >= maxd1){
        maxd1 = maxd;
      }
      //printf("haha\n");
      maxd = 0;
    }
  }
    if(maxd1%2 == 0){
      maxd1 = maxd1*0.5;
    }else{
    maxd1 = maxd1*0.5+1;
    }
    //printf("maxd1: %d seat1: %d seatinf: %d\n",maxd1 ,seat1,seatinf);
    if(maxd1>seat1 && maxd1 > seatinf){
      return maxd1;
    }else if(seat1>seatinf){
      return seat1;
    }else{
      return seatinf;
    }
}

int main() {
    int seats[] = {0,1,0,0,0,0,1,0,0,0};
    int length = sizeof(seats) / sizeof(seats[0]);
    printf("max_distance = %d", max_distance(seats, length));
    return 0;
}