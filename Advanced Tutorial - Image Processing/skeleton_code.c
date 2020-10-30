#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "qdbmp.h"

int sum(int arr[9]){
  int sum = 0;
  for(int i = 0; i < 9; i++){
    sum = sum + arr[i];
  }
  return sum;
}
int main(void) {

    // START CODE HERE (you may test other 8-bit grayscale bmp)
    BMP* imageIn = BMP_ReadFile("lenna.bmp");
    // END CODE HERE

    BMP_CHECK_ERROR(stdout, -1);

    int height = BMP_GetHeight(imageIn);
    int width  = BMP_GetWidth(imageIn);

    BMP* imageOut = BMP_Create(width, height, 8);
    for (int i=0; i<256; i++) {
    	BMP_SetPaletteColor(imageOut, i, i, i, i);
    }
    // START CODE HERE (modify median filter to sobel filter)
    uint8_t window2[9];
    const int sobelx[9] = {1, 0, -1, 2, 0, -2, 1, 0, -1};
    const int sobely[9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
    int outputx[9] = {0};
    int outputy[9] = {0};
    unsigned int magnitude = 0;
    float angle = 0;
    int sumx = 0, sumy = 0;
    uint8_t window[9];
    for (size_t y=1; y<height-1; y++) {
        for (size_t x=1; x<width-1; x++) {
            // Fill the 3x3 window
	        UINT k = 0;
            for (int u=x-1; u<=x+1; u++) {
                for (int v=y-1; v<=y+1; v++) {
                    window[k++] = BMP_GetPixelGray(imageIn, u, v);
                    //printf("%d\n",window[k]);
                }
            }
            // Find the median
            for(uint8_t i=0; i<5; i++) {
                for (uint8_t j=i+1; j<9; j++) {
                    if (window[j] < window[i]) {
                        uint8_t temp = window[i];
                        window[i] = window[j];
                        window[j] = temp;
                    }
                }
            }
            //printf("%d\n",window[4]);
            BMP_SetPixelGray(imageOut, x, y, window[4]);
        }
    }
    BMP* imageOut2 = BMP_Create(width, height, 8);
    for (int i=0; i<256; i++) {
    	BMP_SetPaletteColor(imageOut2, i, i, i, i);
    }
    for (size_t y=1; y<height-1; y++) {
        for (size_t x=1; x<width-1; x++) {
            // Fill the 3x3 window
	        UINT k = 0;
            for (int u=x-1; u<=x+1; u++) {
                for (int v=y-1; v<=y+1; v++) {
                    window2[k++] = BMP_GetPixelGray(imageOut, u, v);
                }
            }
            for(int k=0;k<9;k++){
              outputx[k] = window2[k] * sobelx[k];
              outputy[k] = window2[k] * sobely[k];
              //printf("%d*%d = %d\n",window2[k],sobely[k],outputy[k]);
            }
          sumx = sum(outputx);
          sumy = sum(outputy);
          //printf("sum=%d\n\n",sumy);
          magnitude = sqrt(sumx*sumx+sumy*sumy);
          //printf("%d\n",magnitude);
          angle = atan2(sum(outputy),sum(outputx));

          if(magnitude>100){
            BMP_SetPixelGray(imageOut2, x, y, 255);
          }else{
          BMP_SetPixelGray(imageOut2, x, y, 0);
          }

        }
    }

    // END CODE HERE

    BMP_WriteFile(imageOut2, "output.bmp");

    BMP_Free(imageIn);
    BMP_Free(imageOut);
    return 0;
}
