#include <stdio.h>

int reverse(int x) {
    // Please complete the function body
    int rev = 0;
    while(x > 0){
      rev = (x % 10) + rev * 10;
      x = (x - (x % 10))/10;
      printf("rev: %d x: %d\n", rev,x);
    }
    return rev;
}

int main() {
    int to_reverse = 567434667;
    printf("reverse %d = %d", to_reverse, reverse(to_reverse));
    return 0;
}