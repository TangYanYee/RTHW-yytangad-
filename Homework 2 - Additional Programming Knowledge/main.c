#include "GameField.h"
int main(void) {
STATES state = StartState;
TURN turn = PLAYER1_TURN;
char arr[16][16] = {" ", "1", "2", "3", "4", "5", "6",  "7", "8", "9", "0", "1" , "2", "3", "4", "5"};
pData P1;
pData P2;
pData Comp;
P1.sign = 'X';
P2.sign = 'O';
Comp.sign = 'O';
bool validinp = false;
char start, mode;
bool CompFirstStep = true;
srand(time(0)); 
Comp.x = 0;
Comp.y = 0;

  //pChart(arr);
  while (true){
    validinp = false;
      switch (state){
        
        case StartState:
        printf("Welcome to this game.\n");
        pChart(arr);
        printf("Press enter to START!!\n");
        scanf("%c", &start);
        if(start == '\n'){
        printf("Please enter the number you want to play:\n1: PVP\n2: PVC\n");
        scanf("%c",&mode);
        if(mode == '1'){
          state = GameState;
        }else if(mode == '2'){
          state = SELECT_MODE;
        }else{
          printf("Invalid input");
        }
        }
        break; 

        case GameState:  
          switch (turn){
            case PLAYER1_TURN: 
              printf("Player 1:(format: x-coordinate y-coordinate)\n");
              while(validinp == false){
                scanf("%d %d",&P1.y,&P1.x);
                validinp = ValidInp(P1.x, P1.y, arr,true);
              }
              IChart(P1.x, P1.y, arr,P1);
              turn = PLAYER2_TURN; 
              pChart(arr);
              Win(arr,P1,&state);
              break;

            case PLAYER2_TURN:
              printf("Player 2:(format: x-coordinate y-coordinate)\n");
              while(validinp == false){
              scanf("%d %d",&P2.y,&P2.x);
              validinp = ValidInp(P2.x, P2.y, arr,true);
              }
              IChart(P2.x, P2.y, arr,P2);
              turn = PLAYER1_TURN;  
              pChart(arr);
              Win(arr,P2,&state);
              break;

            case COMP_TURN:
            break;
          } 
            break;
        case SELECT_MODE:
          switch (turn){
            case PLAYER1_TURN: 
              printf("Player 1:(format: x-coordinate y-coordinate)\n");
              while(validinp == false){
                scanf("%d %d",&P1.y,&P1.x);
                validinp = ValidInp(P1.x, P1.y, arr,true);
              }
              IChart(P1.x, P1.y, arr,P1);
              turn = COMP_TURN; 
              pChart(arr);
              Win(arr,P1,&state);
              break;
            case PLAYER2_TURN:
              break;
            case COMP_TURN:
              if(CompFirstStep){
                CompFirstStep = false;
                turn = PLAYER1_TURN; 
                printf("This is how a -IQ computer reacts:\n");
                compWhatevermove(Comp,P1,arr,&Comp.x,&Comp.y);
                pChart(arr);
              }else{
                printf("This is how a -IQ computer reacts:\n");
                //printf("Data outside:%d %d\n",Comp.x,Comp.y);
                VERY_STUPID_COMP(P1,Comp,arr,&Comp.x,&Comp.y);
                turn = PLAYER1_TURN; 
                pChart(arr);
                Win(arr,Comp,&state);
              }
              break;
          } 
        break;
        case EndState:
        printf("Type E to EXIT!! or R to RESTART\n");
        scanf("%c", &start);
          if(start == 'E'){
            return 0;
          }else if(start == 'R'){
            state = StartState;
            break;
          }
          break;
          
        } 
      }
  return 0;
}