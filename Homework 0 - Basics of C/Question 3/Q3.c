#include <stdint.h>
#include <stdio.h>
#include <string.h>
char Roman[] = {'I','V','X','L','C','D','M'};
int arr[] = {1, 5, 10, 50, 100, 500, 1000};
int coutINT = 0;
int roman_to_int(const char s[], int lgth) {
  int coutINT = 0;
  //int lgth = length;
  int convertNum[30] = {0};
    for(int i = 0; i < lgth; i++){
      for(int j = 0; j < 7; j++){
        if(s[i] == Roman[j]){
          convertNum[i] = arr[j];
         // printf("i: %d j:%d convert: %d\n",i,j ,convertNum[i]);
        }
      }
      //printf("length:%d i: %d\n", lgth, i);
    }
    for(int k = 0; k<lgth; k++){
      if(convertNum[k] < convertNum[k+1]){
        coutINT -= convertNum[k];
      }else{
        coutINT += convertNum[k];
      }
      //printf("now: %d, next %d\n",convertNum[k], convertNum[k+1]);
    }
    return coutINT;
}

int main() {
    char roman_num[] = "III";
    char roman_num_2[] = "CXXIII";
    char roman_num_3[] = "MMMCDLIX";

    printf("roman_to_int(%s) = %d\n", roman_num,
           roman_to_int(roman_num, strlen(roman_num)));
    printf("roman_to_int(%s) = %d\n", roman_num_2,roman_to_int(roman_num_2, strlen(roman_num_2)));
    printf("roman_to_int(%s) = %d\n", roman_num_3,roman_to_int(roman_num_3, strlen(roman_num_3)));
}