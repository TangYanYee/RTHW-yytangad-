#include <stdint.h>
#include <stdio.h>
float sumsin = 0;

uint64_t factorial(uint32_t f) {
  // Please complete the function body
  long frac = 1;
    for(int i = 2; i<=f; i++){
    //printf("n: %d i: %lu\n", frac,i);
    frac = frac*i;
    }
    return frac;
}

float _pow(float x, int y) {
    // Please complete the function body
    float pow = x;
    for(int i = 1; i < y; i++){
      pow = pow * x;
    }
    return pow;
}

float taylor_series_sin(float radian) {
  float sin = 0;
    for(int i = 1;i <= 12; i=i+4){
      sin = _pow(radian,i)/factorial(i) - _pow(radian,i+2)/factorial(i+2);
      sumsin = sin +sumsin;
    }
    sumsin += _pow(radian,13)/factorial(13);
    return sumsin;
}

int main() {
    const float PI = 3.14159265f;
    float radian = PI / 3.0f;
    printf("sin(%f) = %f", radian, taylor_series_sin(radian));
    return 0;
}