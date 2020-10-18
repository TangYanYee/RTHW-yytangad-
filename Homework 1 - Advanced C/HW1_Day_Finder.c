#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "i_give_you.h"

char inpdate[10];
day_info InpDay[30];
int cnt = 0;
void printenum_month(int sinp){
  printf("Month: ");
  switch(InpDay[sinp].month){
    case 1: printf("January\n"); break;
    case 2: printf("February\n");break;
    case 3: printf("March\n");break;
    case 4: printf("April\n");break;
    case 5: printf("May\n");break;
    case 6: printf("June\n");break;
    case 7: printf("July\n");break;
    case 8: printf("August\n");break;
    case 9: printf("September\n");break;
    case 10: printf("October\n");break;
    case 11: printf("November\n");break;
    case 12: printf("December\n");break;
  }
}
void printenum_day(int sinp){
  switch(InpDay[sinp].day){
    case SUNDAY: printf("Sunday\n"); break;
    case MONDAY: printf("Monday\n"); break;
    case TUESDAY: printf("Tuesday\n"); break;
    case WEDNESDAY: printf("Wednesday\n"); break;
    case THURSDAY: printf("Thursday\n"); break;
    case FRIDAY: printf("Friday\n"); break;
    case SATURDAY: printf("Saturday\n"); break;
  }
}
void fprintenum_day(FILE * expf, int i){
  switch(InpDay[i].day){
    case SUNDAY: fprintf(expf, "SUNDAY\n"); break;
    case MONDAY: fprintf(expf, "MONDAY\n"); break;
    case TUESDAY: fprintf(expf, "TUESDAY\n"); break;
    case WEDNESDAY: fprintf(expf, "WEDNESDAY\n"); break;
    case THURSDAY: fprintf(expf, "THURSDAY\n"); break;
    case FRIDAY: fprintf(expf, "FRIDAY\n"); break;
    case SATURDAY: fprintf(expf, "SATURDAY\n"); break;
  }
}

bool LeapYr(int year){
  //printf("One more useless day in a year!\n");
    return (((year % 4 == 0) &&(year % 100 != 0)) ||(year % 400 == 0));
}

void WhichDay(){
  bool lpyr = LeapYr(InpDay[cnt].year);
  int monthcode[13] = {0, 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    int thatday = 0;
    thatday = (InpDay[cnt].year%100/4 + InpDay[cnt].year%100)%7 + monthcode[InpDay[cnt].month] + (3 -(InpDay[cnt].year/100)%4)*2 + InpDay[cnt].date;
  if(lpyr && (InpDay[cnt].month == 1 || InpDay[cnt].month == 2)){
    thatday--;
  }
  thatday = thatday%7;
  printf("Day: ");
  switch(thatday){
    case 0: InpDay[cnt].day = SUNDAY; printf("SUNDAY\n"); break;
    case 1: InpDay[cnt].day = MONDAY; printf("MONDAY\n"); break;
    case 2: InpDay[cnt].day = TUESDAY; printf("TUESDAY\n"); break;
    case 3: InpDay[cnt].day = WEDNESDAY; printf("WEDNESDAY\n"); break;
    case 4: InpDay[cnt].day = THURSDAY; printf("THURSDAY\n"); break;
    case 5: InpDay[cnt].day = FRIDAY; printf("FRIDAY\n"); break;
    case 6: InpDay[cnt].day = SATURDAY; printf("SATURDAY\n"); break;
  }
}

void HappyDay(){
  bool multiH = false;
  printf("Name of holiday: "); 
  if(InpDay[cnt].date == 1 && InpDay[cnt].month == 1){
    strcpy(InpDay[cnt].name_of_special_day,"First Day of January");
    multiH = true;
  }else if(InpDay[cnt].date == 29 && InpDay[cnt].month == 1){
    strcpy(InpDay[cnt].name_of_special_day,"Birthday of the Great Tim Woo");
    multiH = true;
  }else if(InpDay[cnt].date == 10 && InpDay[cnt].month == 3){
    strcpy(InpDay[cnt].name_of_special_day,"Mario Day");
    multiH = true;
  }else if(InpDay[cnt].date == 31 && InpDay[cnt].month == 3){
    strcpy(InpDay[cnt].name_of_special_day,"World Backup Day");
    multiH = true;
  }else if(InpDay[cnt].date == 10 && InpDay[cnt].month == 4){
    strcpy(InpDay[cnt].name_of_special_day,"Whatever Day");
    multiH = true;
  }else if(InpDay[cnt].date == 13 && InpDay[cnt].month == 4){
    strcpy(InpDay[cnt].name_of_special_day,"Easter");
    multiH = true;
  }else if(InpDay[cnt].date == 11 && InpDay[cnt].month == 5){
    strcpy(InpDay[cnt].name_of_special_day,"National Technology Day");
    multiH = true;
  }else if(InpDay[cnt].date == 6 && InpDay[cnt].month == 6){
    strcpy(InpDay[cnt].name_of_special_day,"D-Day");
    multiH = true;
  }else if(InpDay[cnt].date == 25 && InpDay[cnt].month == 12){
    strcpy(InpDay[cnt].name_of_special_day,"Christmas");
    multiH = true;
  }else if(InpDay[cnt].date == 26 && InpDay[cnt].month == 12){
    strcpy(InpDay[cnt].name_of_special_day,"Boxing Day");
    multiH = true;
  }else if(InpDay[cnt].day != SUNDAY){
    strcpy(InpDay[cnt].name_of_special_day,"Not a holiday");
  }if(InpDay[cnt].day == SUNDAY && multiH == true){
    strcat(InpDay[cnt].name_of_special_day,", Sunday");
  }else if(InpDay[cnt].day == SUNDAY && multiH == false){
    strcpy(InpDay[cnt].name_of_special_day,"Sunday");
  }
  printf("%s\n", InpDay[cnt].name_of_special_day);
}

bool is_valid_date() {
  bool lpyr = LeapYr(InpDay[cnt].year);
  if(InpDay[cnt].date > 31 || InpDay[cnt].date < 1){//check the date range
  return false;
  }else if(InpDay[cnt].month > 12|| InpDay[cnt].month < 1 ){//check the month range
  return false;
  }else if(InpDay[cnt].year < 1 ){//check the year range
  return false;
  }else if((InpDay[cnt].month == 4||InpDay[cnt].month == 6|| InpDay[cnt].month == 9||InpDay[cnt].month == 11) && InpDay[cnt].date>30){//check "small" month cannot have 31st
    return false;
  }else if(InpDay[cnt].month == 2 && !lpyr && InpDay[cnt].date>28){//not leap year
    return false;
  }else if(InpDay[cnt].month == 2 && lpyr && InpDay[cnt].date>29){//is leap year
    return false;
  }else{
    return  true;
  }
}

void date_input() {
  printf("Please input a date (DD/MM/YYYY): ");
  scanf("%s",inpdate); 
  //turn string into int
  InpDay[cnt].date = (inpdate[0]-48)*10 + (inpdate[1]-48);
  InpDay[cnt].month = (inpdate[3]-48)*10 + (inpdate[4]-48);
  InpDay[cnt].year = (inpdate[6]-48)*1000 + (inpdate[7]-48)*100 + (inpdate[8]-48)*10 + (inpdate[9]-48);
  //printf("DD/MM/YYYY: %d/%d/%d\n", InpDay[cnt].date, InpDay[cnt].month, InpDay[cnt].year);

}

void expFile(){
  FILE * expf;
  expf = fopen ("Day_Finder.txt","w");
  for(int i = 0; i < cnt; i++){
    fprintf(expf, "%d: %02d/%02d/%d\n", i+1, InpDay[i].date ,InpDay[i].month, InpDay[i].year);
    fprintf(expf, "Day: ");
    fprintenum_day(expf,i);
    fprintf(expf, "Name of holiday: %s\n", InpDay[i].name_of_special_day);
  }
 fclose(expf);
}

void import_from_file(){
  int fcnt = cnt*3;
    char str[40];
    FILE *f = fopen("Day_Finder.txt", "r");
    if (!f)
    { fclose(f);
    }
    while (fgets(str, sizeof str, f))
    { fcnt++;
        if (fcnt %3 == 1){
          InpDay[cnt].date = (str[3]-48)*10 + (str[4]-48);
          InpDay[cnt].month = (str[6]-48)*10 + (str[7]-48);
          InpDay[cnt].year = (str[9]-48)*1000 + (str[10]-48)*100 + (str[11]-48)*10 + (str[12]-48);
        }if(fcnt % 3 == 2){
          if(!strcmp(str,"Day: SUNDAY\n")){
          InpDay[cnt].day = SUNDAY;
          }else if(!strcmp(str,"Day: MONDAY\n")){
          InpDay[cnt].day = MONDAY;
          }else if(!strcmp(str,"Day: TUESDAY\n")){
          InpDay[cnt].day = TUESDAY;
          }else if(!strcmp(str,"Day: WEDNESDAY\n")){
          InpDay[cnt].day = WEDNESDAY;
          }else if(!strcmp(str,"Day: THURSDAY\n")){
          InpDay[cnt].day = THURSDAY;
          }else if(!strcmp(str,"Day: FRIDAY\n")){
          InpDay[cnt].day = FRIDAY;
          }else if(!strcmp(str,"Day: SATURDAY\n")){
          InpDay[cnt].day = SATURDAY;
          }
        }if(fcnt % 3 == 0){
          for(int i = 17; i < strlen(str); i++){
          strncat(InpDay[cnt].name_of_special_day, &str[i],1);
          if(str[i+1] == '\n'){
            break;
          }
          }
          //printf("NAME: %s",InpDay[cnt].name_of_special_day);
          cnt = fcnt/3;
        }
    }
    fclose(f);
}

void select_saved_data(){
  int sinp;
  if (cnt==0){
    invalid_input_msg();
  }else{
    printf("Here is the list of saved data:\n");
    for(int i=0; i < cnt; i++){
      printf("%d: %02d/%02d/%d\n", i+1, InpDay[i].date ,InpDay[i].month, InpDay[i].year);
    }
    printf("Please select the saved data from the list:\n");
    scanf("%d", &sinp);
    printf("Date: %02d\n", InpDay[sinp-1].date);
    printenum_month(sinp-1);
    printf("Year: %d\n", InpDay[sinp-1].year);
    printf("Day: ");
    printenum_day(sinp-1);
    printf("Name of holiday: %s\n", InpDay[sinp-1].name_of_special_day);
    if(strcmp(InpDay[sinp-1].name_of_special_day, "Not a holiday")){
      printf("It is a holiday! :)\n");
    }else{
      printf("It is not a holiday... :(\n");
    }
  }

}

void main_loop(){
  choice_menu();
  char choice;
  while(1){
  scanf("%c", &choice);
  if(choice == DATE_INPUT){
    bool valid = 0;
    //input the date and check validity
    while(!valid){
      date_input();
      valid = is_valid_date();
      if(!valid){
        printf("You input the wrong date, Please try again\n");
      }
    }
    WhichDay();
    HappyDay();
    cnt++;
  }else if (choice == IMPORT_FROM_FILE){
    import_from_file();
  }else if (choice == SELECT_SAVED_DATA){
    select_saved_data();
  }else if (choice == END_PROGRAM){
    break;
  }else if(choice != 10){
  /*printf("\nPLEASE READ THE MENU VERY EXTREMELY CAREFUL AND TYPE AGAIN!!!\n\n\n");
  choice_menu();*/
  invalid_input_msg();
  }
  }expFile();
}
/*
*
* Your code ends here
*
*/
int main(void) {
  opening();
  main_loop();
  return 0;
}

