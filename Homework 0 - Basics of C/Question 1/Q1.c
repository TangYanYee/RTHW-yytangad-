#include <stdint.h>
#include <stdio.h>

// uint64_t = unsigned 64-bit integer
uint64_t factorial(uint32_t f) {
    // Please complete the function body
    long n = 1;
    for(int i = 2; i<=f; i++){
      //printf("n: %d i: %lu\n", n,i);
      n = n*i;
    }
    return n;
}

int main() {
    //You can modify main function for testing purpose
    for (int i = 0; i < 15; i++) {
        printf("%d! = %lu\n", i, factorial(i));
    }
    return 0;
}