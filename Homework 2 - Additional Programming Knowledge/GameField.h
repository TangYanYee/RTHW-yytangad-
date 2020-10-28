//You need to implement a struct called FiveInRowField, and some other helper functions like SetX(), SetO, printField(), Checkwin()
#include "Basic.h"
typedef struct {
    int x;
    int y;
    char sign;
} pData;//This is called FiveInRowField actually ;)
typedef struct {
    int x;
    int y;
} dntMove;
void pChart(char arr[16][16]){
  //this fuction is for printing the chart which  is equal to printField()
  int cnt[6] = {0,0,0,0,0,0};
    for(int x = 0; x < 16; x++){
      for(int y = 0; y < 16; y++){
        if(x == 0 && y > 0){
          if(y < 10){
            arr[x][y] = y+'0';
          }else{
            arr[x][y] = y+'0' - 10;
          }
        }
        if(arr[x][y] == 0){
          printf(". ");
        }else{
        printf("%c ", arr[x][y]);
        }
      }
      if(x == 0){
        printf("x");
      }
      printf("\n");
    } 
    printf("y\n\n");
}
void IChart(int x, int y, char arr[16][16],pData P){//this is SetX(), SetO but i do it in one fuction because i am lazy:)
    arr[x][y] = P.sign;
}
bool ValidInp(int x, int y,char arr[16][16],bool isPpl){//this fuction is for checking whether the user make stupid mistake
  if((x > 0 && x < 16) && (y > 0 && y < 16)&&(arr[x][y]==0)){
    return true;
  }else {
    if(isPpl){
    printf("Invalid Input!Please try again!\n");
    }
    return false;
  }
}
void Win_1(char arr[16][16], int cnt[6],STATES* state ,pData P,int x,int y, int k,bool winned,bool *adwin){
  //this is sub fuction because i am lazy so i make this to make it look somehow "shorter"
  if((arr[x][y] == P.sign && x > 0 && x < 16) && winned == false){
        cnt[k]++;
        if(cnt[k] == 5){
          *state = EndState;
          *adwin = true;
          if(P.sign == 'X'){
            printf("P1 Win!!\n");
            printf("Type E to EXIT!!\n");
          }else{
            printf("P2 Win!!\n");
            printf("Type E to EXIT!!\n");
          } 
        }
  }else{
    cnt[k] = 0;
  }
}
void Win(char arr[16][16],pData P,STATES* state){//P1:X P2:O
//this is the fuction which check whether user win or not
  bool winned = false;
  int cnt[6] = {0,0,0,0,0,0};
  for(int x = 1; x < 16; x++){
   int i = 0;
    for(int y = 1; y < 16; y++){
      Win_1(arr,cnt,state,P,x,y,0,winned,&winned);//vertical
      Win_1(arr,cnt,state,P,y,x,1,winned,&winned);//horrizontal
      Win_1(arr,cnt,state,P,x+i-15,y,2,winned,&winned);//oblique 1 uppercase
      Win_1(arr,cnt,state,P,x+i,y,3,winned,&winned);//oblique 1 lowercase
      Win_1(arr,cnt,state,P,y,x-i,4,winned,&winned);//oblique 2 uppercase
      Win_1(arr,cnt,state,P,y,16+x-i,5,winned,&winned);//oblique 2 lowercase
      i++;
    }
  }
} 
//WARNING: It is a chaos below!!! so i make some comments to help u :P
void Win_continuous(char arr[16][16], int cnt[6],pData P1, pData Comp,int x,int y, int k,bool compMove,bool * adcompMove){//this is for comp check whether user make a line of 3/4 or not 
  if(arr[x][y] == 'X' && x > 0 && x < 16){
    cnt[k]++;
    if(cnt[k] >= 3){
      switch(k){
        case 0: //horizontal
        if(arr[x][y] == 'X' && arr[x][y+1] == 0 && y+1<16 && compMove == false){
          Comp.x = x;
          Comp.y = y+1;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }else if(arr[x][y-cnt[k]+1] == 'X' && arr[x][y-cnt[k]] == 0 && y-cnt[k]+1>1 && compMove == false){
          Comp.x = x;
          Comp.y = y-cnt[k];
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }
        break;
        case 1: //vertical
        if(arr[x][y] == 'X' && arr[x+1][y] == 0 && x+1<16 && compMove == false){
          Comp.x = x+1;
          Comp.y = y;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp); 
        }else if(arr[x-cnt[k]+1][y] == 'X' && arr[x-cnt[k]][y] == 0 && x-cnt[k]+1>1 && compMove == false){
          Comp.x = x-cnt[k];
          Comp.y = y;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp); 
        }
        break;
        case 2: //oblique1
        if(arr[x][y] == 'X' && arr[x+1][y+1] == 0 && y+1<16&& x+1<16 && compMove == false){
          Comp.x = x+1;
          Comp.y = y+1;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }else if(arr[x-cnt[k]+1][y-cnt[k]+1] == 'X' && arr[x-cnt[k]][y-cnt[k]] == 0 && y-cnt[k]+1>1&& x-cnt[k]+1>1 && compMove == false){
          Comp.x = x-cnt[k];
          Comp.y = y-cnt[k];
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }
        break;
        case 3: //oblique1
        if(arr[x][y] == 'X' && arr[x+1][y+1] == 0 && y+1<16&& x+1<16 && compMove == false){
          Comp.x = x+1;
          Comp.y = y+1;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }else if(arr[x-cnt[k]+1][y-cnt[k]+1] == 'X' && arr[x-cnt[k]][y-cnt[k]] == 0 && y-cnt[k]+1>1&& x-cnt[k]+1>1 && compMove == false){
          Comp.x = x-cnt[k];
          Comp.y = y-cnt[k];
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }
        break;
        case 4: //oblique2
        if(arr[x][y] == 'X' && arr[x+1][y-1] == 0 && y-1>0&& x+1<16 && compMove == false){
          Comp.x = x+1;
          Comp.y = y-1;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }else if(arr[x-cnt[k]+1][y+cnt[k]-1] == 'X' && arr[x+cnt[k]][y+cnt[k]] == 0 && y-cnt[k]+1>1 && compMove == false){
          Comp.x = x-cnt[k];
          Comp.y = y+cnt[k];
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }
        break;
        case 5: //oblique2
        if(arr[x][y] == 'X' && arr[x+1][y-1] == 0 && y-1>0&& x+1<16 && compMove == false){
          Comp.x = x+1;
          Comp.y = y-1;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }else if(arr[x-cnt[k]+1][y+cnt[k]-1] == 'X' && arr[x+cnt[k]][y+cnt[k]] == 0 && y-cnt[k]+1>1 && compMove == false){
          Comp.x = x-cnt[k];
          Comp.y = y+cnt[k];
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }

        break;
      }
    }
  }else{
    cnt[k] = 0;
  }
}
void Win_break(char arr[16][16], int cnt[6],pData P1, pData Comp,int x,int y, int k,bool compMove,bool * adcompMove){//this is for comp to check whether user win like XX X, X XX, XX XX
  switch(k){
    case 0:
      if(arr[x][y] == 'X' && arr[x][y+1] == 0 && arr[x][y+2] == 'X' && y-1 > 0 && y+3 < 16&& compMove == false){
        //printf("haha0\n");
        if(arr[x][y+3] == 'X'||arr[x][y-1] == 'X'){
        Comp.x = x;
        Comp.y = y+1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
    break;
    case 1:
      if(arr[x][y] == 'X' && arr[x+1][y] == 0 && arr[x+2][y] == 'X' && x > 0 && x < 16&& compMove == false){
        //printf("haha1\n");
        if((arr[x+3][y] == 'X'||arr[x-1][y] == 'X')){
        Comp.x = x+1;
        Comp.y = y;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
      break;
    case 2:
      if(arr[x][y] == 'X' && arr[x+1][y+1] == 0 && arr[x+2][y+2] == 'X' && x > 0 && x < 16&& compMove == false){
        //printf("haha2\n");
        if((arr[x+3][y+3] == 'X'||arr[x-1][y-1] == 'X')){
        Comp.x = x+1;
        Comp.y = y+1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
    break;
    case 3:
      if(arr[x][y] == 'X' && arr[x+1][y+1] == 0 && arr[x+2][y+2] == 'X' && x > 0 && x < 16&& compMove == false){
        //printf("haha3\n");
        if(arr[x+3][y+3] == 'X'||arr[x-1][y-1] == 'X'){
        Comp.x = x+1;
        Comp.y = y+1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
    break;
    case 4:
      if(arr[x][y] == 'X' && arr[x+1][y-1] == 0 && arr[x+2][y-2] == 'X' && x > 0 && x < 16&& compMove == false){
        //printf("haha4\n");
        if((arr[x+3][y-3] == 'X'||arr[x-1][y+1] == 'X')){
        Comp.x = x+1;
        Comp.y = y-1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
    break;
    case 5:
      if(arr[x][y] == 'X' && arr[x+1][y-1] == 0 && arr[x+2][y-2] == 'X' && x > 0 && x < 16&& compMove == false){
        //printf("haha5\n");
        if((arr[x+3][y-3] == 'X'||arr[x-1][y+1] == 'X')){
        Comp.x = x+1;
        Comp.y = y-1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
    break;
  }
}
void Win_sure(char arr[16][16], int cnt[6],pData P1, pData Comp,int x,int y, int k,bool compMove,bool * adcompMove){//this is use for checking whether comp can win in OO O, O OO, OO OO
  switch(k){
    case 0:
      if(arr[x][y] == 'O' && arr[x][y+1] == 0 && arr[x][y+2] == 'O' && y-1 > 0 && y+3 < 16&& compMove == false){
        if(arr[x][y+3] == 'O'||arr[x][y-1] == 'O'){
        Comp.x = x;
        Comp.y = y+1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
    break;
    case 1:
      if(arr[x][y] == 'O' && arr[x+1][y] == 0 && arr[x+2][y] == 'O' && x > 0 && x < 16&& compMove == false){
        if((arr[x+3][y] == 'O'||arr[x-1][y] == 'O')){
        Comp.x = x+1;
        Comp.y = y;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
      break;
    case 2:
      if(arr[x][y] == 'O' && arr[x+1][y+1] == 0 && arr[x+2][y+2] == 'O' && x > 0 && x < 16&& compMove == false){
        if((arr[x+3][y+3] == 'O'||arr[x-1][y-1] == 'O')){
        Comp.x = x+1;
        Comp.y = y+1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
    break;
    case 3:
      if(arr[x][y] == 'O' && arr[x+1][y+1] == 0 && arr[x+2][y+2] == 'O' && x > 0 && x < 16&& compMove == false){
        if(arr[x+3][y+3] == 'O'||arr[x-1][y-1] == 'O'){
        Comp.x = x+1;
        Comp.y = y+1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
    break;
    case 4:
      if(arr[x][y] == 'O' && arr[x+1][y-1] == 0 && arr[x+2][y-2] == 'O' && x > 0 && x < 16&& compMove == false){
        if((arr[x+3][y-3] == 'O'||arr[x-1][y+1] == 'O')){
        Comp.x = x+1;
        Comp.y = y-1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
    break;
    case 5:
      if(arr[x][y] == 'O' && arr[x+1][y-1] == 0 && arr[x+2][y-2] == 'O' && x > 0 && x < 16&& compMove == false){
        if((arr[x+3][y-3] == 'O'||arr[x-1][y+1] == 'O')){
        Comp.x = x+1;
        Comp.y = y-1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
        }
      }
    break;
  }
}
void Win_OOO(char arr[16][16], int cnt[6],pData P1, pData Comp,int x,int y, int k,bool compMove,bool * adcompMove){//this is use for checking whether comp can win in OO O, O OO, OO OO
  switch(k){
    case 0:
      if(arr[x][y] == 'O' && arr[x][y+1] == 0 && arr[x][y+2] == 'O' && y-1 > 0 && y+3 < 16&& compMove == false){
        Comp.x = x;
        Comp.y = y+1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
      }
    break;
    case 1:
      if(arr[x][y] == 'O' && arr[x+1][y] == 0 && arr[x+2][y] == 'O' && x > 0 && x < 16&& compMove == false){
        Comp.x = x+1;
        Comp.y = y;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
      }
      break;
    case 2:
      if(arr[x][y] == 'O' && arr[x+1][y+1] == 0 && arr[x+2][y+2] == 'O' && x > 0 && x < 16&& compMove == false){
        Comp.x = x+1;
        Comp.y = y+1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
      }
    break;
    case 3:
      if(arr[x][y] == 'O' && arr[x+1][y+1] == 0 && arr[x+2][y+2] == 'O' && x > 0 && x < 16&& compMove == false){
        Comp.x = x+1;
        Comp.y = y+1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
      }
    break;
    case 4:
      if(arr[x][y] == 'O' && arr[x+1][y-1] == 0 && arr[x+2][y-2] == 'O' && x > 0 && x < 16&& compMove == false){
        Comp.x = x+1;
        Comp.y = y-1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
      }
    break;
    case 5:
      if(arr[x][y] == 'O' && arr[x+1][y-1] == 0 && arr[x+2][y-2] == 'O' && x > 0 && x < 16&& compMove == false){
        Comp.x = x+1;
        Comp.y = y-1;
        *adcompMove = true;
        IChart(Comp.x, Comp.y, arr,Comp);
      }
    break;
  }
}
/*bool possibleMove(char arr[16][16], int cnt[6],pData P1, pData Comp,int x,int y, int k,bool compMove,bool * adcompMove,bool firstX, bool*adfirstX,dntMove nMove[30]){
  if(firstX == false && arr[x][y] == 'X'){
    switch(k){
      case 0:
      nMove[0].x = x;
      nMove[0].y = y;
      break;
      case 1:
      nMove[2].x = y;
      nMove[2].y = x;
      break;
      case 2:
      nMove[4].x = x;
      nMove[4].y = y;
      break;
      case 3:
      nMove[6].x = x;
      nMove[6].y = y;
      break;
      case 4:
      nMove[8].x = x;
      nMove[8].y = y;
      break;
      case 5:
      nMove[10].x = x;
      nMove[10].y = y;
      break;
    }
    *adfirstX = true;
  }else if(firstX == true && arr[x][y] == 'X'){
    *adfirstX = false;
     if(cnt[k] < 5){
      switch(k){
        case 0: //horizontal
        nMove[1].x = x;
        nMove[1].y = y;
        return false;
        break;
        case 1: //vertical
        nMove[3].y = x;
        nMove[3].x = y;
        return false;
        break;
        case 2: //oblique1
        nMove[5].x = x;
        nMove[5].y = y;
        return false;
        break;
        case 3: //oblique1
        nMove[7].x = x;
        nMove[7].y = y;
        return false;
        break;
        case 4: //oblique2
        nMove[9].x = x;
        nMove[9].y = y;
        return false;
        break;
        case 5: //oblique2
        nMove[11].x = x;
        nMove[11].y = y;
        return false;
        break;
      }
    }else{
      return true;
    }
    cnt[k] = 0;
  }
  if((arr[x][y] == 'O' || arr[x][y] == 0) && x > 0 && x < 16 && firstX == true){
    cnt[k]++;
  }
}*/
void Win_attack(char arr[16][16], int cnt[6],pData P1, pData Comp,int x,int y, int k,bool compMove,bool * adcompMove,int h){/*
  when k = 4, it will try to make OOOOO;
  when k = 3, it will try to do OOOO;(this is at the same case with human make XXX and comp need to defend, so it somehow depend on luck whether it will attack or OFFENSE)
  when k = 2, it will try to make OOO;
  */
  if(arr[x][y] == 'O' && x > 0 && x < 16){
    cnt[k]++;
    if(cnt[k] >= h){
      //printf("%dATTACK!!\n",h);
      switch(k){
        case 0: //horizontal
        if(arr[x][y] == 'O' && arr[x][y+1] == 0 && y+1<16 && compMove == false){
          Comp.x = x;
          Comp.y = y+1;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }else if(arr[x][y-cnt[k]+1] == 'O' && arr[x][y-cnt[k]] == 0 && y-cnt[k]+1>1 && compMove == false){
          Comp.x = x;
          Comp.y = y-cnt[k];
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }
        break;
        case 1: //vertical
        if(arr[x][y] == 'O' && arr[x+1][y] == 0 && x+1<16 && compMove == false){
          Comp.x = x+1;
          Comp.y = y;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp); 
        }else if(arr[x-cnt[k]+1][y] == 'O' && arr[x-cnt[k]][y] == 0 && x-cnt[k]+1>1 && compMove == false){
          Comp.x = x-cnt[k];
          Comp.y = y;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp); 
        }
        break;
        case 2: //oblique1
        if(arr[x][y] == 'O' && arr[x+1][y+1] == 0 && y+1<16&& x+1<16 && compMove == false){
          Comp.x = x+1;
          Comp.y = y+1;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }else if(arr[x-cnt[k]+1][y-cnt[k]+1] == 'O' && arr[x-cnt[k]][y-cnt[k]] == 0 && y-cnt[k]+1>1&& x-cnt[k]+1>1 && compMove == false){
          Comp.x = x-cnt[k];
          Comp.y = y-cnt[k];
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }
        break;
        case 3: //oblique1
        if(arr[x][y] == 'O' && arr[x+1][y+1] == 0 && y+1<16&& x+1<16 && compMove == false){
          Comp.x = x+1;
          Comp.y = y+1;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }else if(arr[x-cnt[k]+1][y-cnt[k]+1] == 'O' && arr[x-cnt[k]][y-cnt[k]] == 0 && y-cnt[k]+1>1&& x-cnt[k]+1>1 && compMove == false){
          Comp.x = x-cnt[k];
          Comp.y = y-cnt[k];
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }
        break;
        case 4: //oblique2
        if(arr[x][y] == 'O' && arr[x+1][y-1] == 0 && y-1>0&& x+1<16 && compMove == false){
          Comp.x = x+1;
          Comp.y = y-1;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }else if(arr[x-cnt[k]+1][y+cnt[k]-1] == 'O' && arr[x+cnt[k]][y+cnt[k]] == 0 && y-cnt[k]+1>1 && compMove == false){
          Comp.x = x-cnt[k];
          Comp.y = y+cnt[k];
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }
        break;
        case 5: //oblique2
        if(arr[x][y] == 'O' && arr[x+1][y-1] == 0 && y-1>0&& x+1<16 && compMove == false){
          Comp.x = x+1;
          Comp.y = y-1;
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }else if(arr[x-cnt[k]+1][y+cnt[k]-1] == 'O' && arr[x+cnt[k]][y+cnt[k]] == 0 && y-cnt[k]+1>1 && compMove == false){
          Comp.x = x-cnt[k];
          Comp.y = y+cnt[k];
          *adcompMove = true;
          IChart(Comp.x, Comp.y, arr,Comp);  
        }

        break;
      }
    }
  }else{
    cnt[k] = 0;
  }
}

void compWhatevermove(pData Comp,pData P, char arr[16][16],int*x,int*y){//this is for comp to randomly select the path
  *x = P.x+rand()%3 -1;
  *y = P.y+rand()%3 -1;
  while(!ValidInp(*x, *y, arr,false)){
    *x = P.x+rand()%3 -1;
    *y = P.y+rand()%3 -1;
  }
  IChart(*x, *y, arr,Comp);

}
void VERY_STUPID_COMP(pData P, pData Comp, char arr[16][16],int*Compx,int*Compy){
  int cnt[6] = {0,0,0,0,0,0};
  bool compMove = false;
  bool firstX = false;
  bool possible[6] = {true,true,true,true,true,true};
  int cntO[6] = {0,0,0,0,0,0};
  dntMove nMove[30];
  for(int x = 1; x < 16; x++){
   int i = 0;
    for(int y = 1; y < 16; y++){
      Win_attack(arr,cntO,P,Comp,x,y,0,compMove,&compMove,4);//horizontal
      Win_attack(arr,cntO,P,Comp,y,x,1,compMove,&compMove,4);//vertical
      Win_attack(arr,cntO,P,Comp,x+i-15,y,2,compMove,&compMove,2);//oblique 1 uppercase
      Win_attack(arr,cntO,P,Comp,x+i,y,3,compMove,&compMove,4);//oblique 1 lowercase
      Win_attack(arr,cntO,P,Comp,y,x-i,4,compMove,&compMove,4);//oblique 2 uppercase
      Win_attack(arr,cntO,P,Comp,y,16-i+x,5,compMove,&compMove,4);//oblique 2 lowercase
      Win_sure(arr,cnt,P,Comp,x,y,0,compMove,&compMove);
      Win_sure(arr,cnt,P,Comp,x,y,1,compMove,&compMove);
      Win_sure(arr,cnt,P,Comp,x,y,2,compMove,&compMove);
      Win_sure(arr,cnt,P,Comp,x,y,3,compMove,&compMove);
      Win_sure(arr,cnt,P,Comp,x,y,4,compMove,&compMove);
      Win_sure(arr,cnt,P,Comp,x,y,5,compMove,&compMove);
      Win_break(arr,cnt,P,Comp,x,y,0,compMove,&compMove);
        Win_break(arr,cnt,P,Comp,x,y,1,compMove,&compMove);
        Win_break(arr,cnt,P,Comp,x,y,2,compMove,&compMove);
        Win_break(arr,cnt,P,Comp,x,y,3,compMove,&compMove);
        Win_break(arr,cnt,P,Comp,x,y,4,compMove,&compMove);
        Win_break(arr,cnt,P,Comp,x,y,5,compMove,&compMove);
      i++;
    }
  }
  /*if(compMove == false){
    for(int x = 1; x < 16; x++){
      int i = 0;
      for(int y = 1; y < 16; y++){
      possible[0] = possibleMove(arr, cnt,P, Comp,x,y,0,compMove,&compMove,firstX, &firstX,nMove);
      possible[1] = possibleMove(arr, cnt,P, Comp,y,x,1,compMove,&compMove,firstX, &firstX,nMove);
      possible[2] = possibleMove(arr, cnt,P, Comp,x+i-15,y,2,compMove,&compMove,firstX, &firstX,nMove);
      possible[3] = possibleMove(arr, cnt,P, Comp,x+i,y,3,compMove,&compMove,firstX, &firstX,nMove);
      possible[4] = possibleMove(arr, cnt,P, Comp,y,x-i,4,compMove,&compMove,firstX, &firstX,nMove);
      possible[5] = possibleMove(arr, cnt,P, Comp,y,16-i+x,5,compMove,&compMove,firstX, &firstX,nMove);
      printf("possible: %d\n", possible[0]);
      printf("nMove1:%d %d\n", nMove[0].x,nMove[0].y);
      printf("nMove2:%d %d\n", nMove[1].x,nMove[1].y);
      i++;
      }
    }
  }*/
  if(compMove == false){
    for(int x = 1; x < 16; x++){
    int i = 0;
      //printf("OFFENSE");
      for(int y = 1; y < 16; y++){
        
        Win_continuous(arr,cnt,P,Comp,x,y,0,compMove,&compMove);//horizontal
        Win_continuous(arr,cnt,P,Comp,y,x,1,compMove,&compMove);//vertical
        Win_continuous(arr,cnt,P,Comp,x+i-15,y,2,compMove,&compMove);//oblique 1 uppercase
        Win_continuous(arr,cnt,P,Comp,x+i,y,3,compMove,&compMove);//oblique 1 lowercase
        Win_continuous(arr,cnt,P,Comp,y,x-i,4,compMove,&compMove);//oblique 2 uppercase
        Win_continuous(arr,cnt,P,Comp,y,16-i+x,5,compMove,&compMove);//oblique 2 lowercase
        Win_OOO(arr,cnt,P,Comp,x,y,0,compMove,&compMove);
        Win_OOO(arr,cnt,P,Comp,x,y,1,compMove,&compMove);
        Win_OOO(arr,cnt,P,Comp,x,y,2,compMove,&compMove);
        Win_OOO(arr,cnt,P,Comp,x,y,3,compMove,&compMove);
        Win_OOO(arr,cnt,P,Comp,x,y,4,compMove,&compMove);
        Win_OOO(arr,cnt,P,Comp,x,y,5,compMove,&compMove);
        Win_attack(arr,cntO,P,Comp,x,y,0,compMove,&compMove,3);//horizontal
        Win_attack(arr,cntO,P,Comp,y,x,1,compMove,&compMove,3);//vertical
        Win_attack(arr,cntO,P,Comp,x+i-15,y,2,compMove,&compMove,3);//oblique 1 uppercase
        Win_attack(arr,cntO,P,Comp,x+i,y,3,compMove,&compMove,3);//oblique 1 lowercase
        Win_attack(arr,cntO,P,Comp,y,x-i,4,compMove,&compMove,3);//oblique 2 uppercase
        Win_attack(arr,cntO,P,Comp,y,16-i+x,5,compMove,&compMove,3);//oblique 2 lowercase
        
        i++;
      }
    }
  }
    for(int x = 1; x < 16; x++){
    int i = 0;
      for(int y = 1; y < 16; y++){
        Win_attack(arr,cntO,P,Comp,x,y,0,compMove,&compMove,2);//horizontal
        Win_attack(arr,cntO,P,Comp,y,x,1,compMove,&compMove,2);//vertical
        Win_attack(arr,cntO,P,Comp,x+i-15,y,2,compMove,&compMove,2);//oblique 1 uppercase
        Win_attack(arr,cntO,P,Comp,x+i,y,3,compMove,&compMove,2);//oblique 1 lowercase
        Win_attack(arr,cntO,P,Comp,y,x-i,4,compMove,&compMove,2);//oblique 2 uppercase
        Win_attack(arr,cntO,P,Comp,y,16-i+x,5,compMove,&compMove,2);//oblique 2 lowercase
        i++;
      }
    }
  if(compMove == false){
    compWhatevermove(Comp,Comp,arr,Compx,Compy);
    compMove = true;
  }
  if(compMove == false){
    *Compx = rand()%16;
    *Compy = rand()%16;
    while(!ValidInp(*Compx, *Compy, arr,false)){
      *Compx = rand()%16;
      *Compy = rand()%16;
  }
  }
}
