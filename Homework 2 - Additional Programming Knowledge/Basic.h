//Bacis.h: all the enums and states should be defined here
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum {
  PLAYER1_TURN,
  PLAYER2_TURN,
  COMP_TURN
}TURN;
typedef enum { 
  StartState, GameState, SELECT_MODE, EndState         
} STATES;
typedef struct {
    int x;
    int y;
    char sign;
} pData;