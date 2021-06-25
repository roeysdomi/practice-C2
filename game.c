#include <stdio.h>
#include<stdbool.h>
#include <math.h>

#define LINES 7
#define COL 8
int col1=0;
int col2=0;
int col3=0;
int col4=0;
int col5=0;
int col6=0;
int col7=0;
int player=1;
int over=0;
double recored[42];

int board [COL][LINES];
void start();
void loopchooice(int *recs);
bool checkifok(double num,int *recs);
void printboard();
void checkwin();
void select(double num,int *recs);
void undo(int *recsize);

void printboard()

{    
    for(int i=5;i>-1;i--)
      {
          for(int j=0;j<7;j++)
          {
               if(board[i][j]==0){printf("| ");}
               if(board[i][j]==1){printf("|x");}
               if(board[i][j]==2){printf("|o");}
          }
          printf("| \n");
      }
      printf(" 1 2 3 4 5 6 7 \n");
}
void checkwin()
{    
    for(int i=5;i>-1;i--)
      {
          for(int j=0;j<7;j++)
          {
              if(0<=i&&i<=2&&0<=j&&j<=3)
              { 
                  ///---אלכסון ימני
                  if(board[i][j]+board[i+1][j+1]+board[i+2][j+2]+board[i+3][j+3]==4
                  &&board[i][j]==1&&board[i+1][j+1]==1&&board[i+2][j+2]==1&&board[i+3][j+3]==1)
                  {printf(" X player won ");over=1;return;}
                  if(board[i][j]+board[i+1][j+1]+board[i+2][j+2]+board[i+3][j+3]==8
                  &&board[i][j]==2&&board[i+1][j+1]==2&&board[i+2][j+2]==2&&board[i+3][j+3]==2)
                  {printf(" O player won ");over=1;return;}
              }
              if(0<=i&&i<=5&&0<=j&&j<=3)
              {  ///שורה
                  
                  if(board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3]==4
                  &&board[i][j]==1&&board[i][j+1]==1&&board[i][j+2]==1&&board[i][j+3]==1)
                  {printf(" X player won ");over=1;return;}
                  if(board[i][j]+board[i][j+1]+board[i][j+2]+board[i][j+3]==8
                  &&board[i][j]==2&&board[i][j+1]==2&&board[i][j+2]==2&&board[i][j+3]==2)
                  {printf(" O player won ");over=1;return;}
              }
              if(0<=i&&i<=2&&3<=j&&j<=6)
              { 
                  
                   if(board[i][j]+board[i+1][j-1]+board[i+2][j-2]+board[i+3][j-3]==4
                   &&board[i][j]==1&&board[i+1][j-1]==1&&board[i+2][j-2]==1&&board[i+3][j-3]==1)
                  {printf(" X player won ");over=1;return;}
                  if(board[i][j]+board[i+1][j-1]+board[i+2][j-2]+board[i+3][j-3]==8
                 &&board[i][j]==2&&board[i+1][j-1]==2&&board[i+2][j-2]==2&&board[i+3][j-3]==2)
                  {printf(" O player won ");over=1;return;}
              }
              if(0<=i&&i<=2&&0<=j&&j<=6)
              { 
                  ///rows
                   if(board[i][j]+board[i+1][j]+board[i+2][j]+board[i+3][j]==4
                   &&board[i][j]==1&&board[i+1][j]==1&&board[i+2][j]==1&&board[i+3][j]==1)
                  {printf(" X player won ");over=1;return;}
                  if(board[i][j]+board[i+1][j]+board[i+2][j]+board[i+3][j]==8
                  &&board[i][j]==2&&board[i+1][j]==2&&board[i+2][j]==2&&board[i+3][j]==2)
                  {printf(" O player won ");over=1;return;}
              }
          }
         
      }
      
}
void select(double num,int *recs)
{          if(num ==0&&(*recs)==0){printf("||Board is empty - can't undo!||\n");loopchooice(recs);}
           if(num==0){undo(recs);loopchooice(recs);}
           if(over==1){printf("\n =====game over=====\n");return;}
          checkfloat(num);
        
         if(checkifok(num,recs)){
            int num2=(int)num;
            recored[(*recs)++]=num2;
            int check=0;
            if(num2==1)
            {board[col1][num2-1]=player;col1=col1+1;}
            if(num2==2)
            {board[col2][num2-1]=player;col2=col2+1;}
            if(num2==3)
            {board[col3][num2-1]=player;col3=col3+1;}
            if(num2==4)
            {board[col4][num2-1]=player;col4=col4+1;}
            if(num2==5)
            {board[col5][num2-1]=player;col5=col5+1;}
            if(num2==6)
            {board[col6][num2-1]=player;col6=col6+1;}
            if(num2==7)
            {board[col7][num2-1]=player;col7=col7+1;}
            if(player==1&&check==0)
            {player=2;check=1;}
            if(player==2&&check==0)
            {player=1;check=1;}
            printboard();
            checkwin();
             if(over==1){printf("\n =====game over=====\n");return;}
         }  
}
bool checkifok(double num,int *recs)
{ 
     
     
     if(col1+col2+col3+col4+col5+col6+col7==42){printf("||It`s a tie ! ||\n");over=1;return false;}
     if(num==1&&col1==6)
     {printf("|| Invalid input, this column is full. Please choose another one: ||\n");loopchooice(recs);}
     if(num==2&&col2>=6)
     {printf("|| Invalid input, this column is full. Please choose another one: ||\n");loopchooice(recs);}
     if(num==3&&col3>=6)
     {printf("|| Invalid input, this column is full. Please choose another one: ||\n");loopchooice(recs);}
     if(num==4&&col4>=6)
     {printf("|| Invalid input, this column is full. Please choose another one: ||\n");loopchooice(recs);}
     if(num==5&&col5>=6)
     {printf("|| Invalid input, this column is full. Please choose another one: ||\n");loopchooice(recs);}
     if(num==6&&col6>=6)
     {printf("|| Invalid input, this column is full. Please choose another one: ||\n");loopchooice(recs);}
     if(num==7&&col7>=6)
     {printf("|| Invalid input, this column is full. Please choose another one: ||\n");loopchooice(recs);}
     if(num<1||num>7)
     {printf("\n ||Invalid input, the number must be between 1 to 7:||\n");loopchooice(recs);}
   else

   return true;
}
void checkfloat(double num)
{
    float number=num;
     int a=(int)num;
     if(num-a!=0){printf("||Invalid input, bye-bye! ||\n");over=1;}
     
     
}
void loopchooice(int *recs)
{   
    
    
    if(over!=1)
    {
      printboard();
    if(player==1){printf("\n ||player X enter your`e chooice :||\n\n\n");}
    if(player==2){printf("\n ||player O enter your`e chooice :||\n\n\n");}
    double chooice;
    
    scanf("%lf",&chooice);
    select(chooice,recs);
    
    printf("\n");
   
    loopchooice(recs);
        
    }
}
void undo(int *recsize)
{
    (*recsize)--;
    
    int check=0;
    
    if(recored[(*recsize)]==1){board[col1-1][0]=0;col1--;}
    if(recored[(*recsize)]==2){board[col2-1][1]=0;col2--;}
    if(recored[(*recsize)]==3){board[col3-1][2]=0;col3--;}
    if(recored[(*recsize)]==4){board[col4-1][3]=0;col4--;}
    if(recored[(*recsize)]==5){board[col5-1][4]=0;col5--;}
    if(recored[(*recsize)]==6){board[col6-1][5]=0;col6--;}
    if(recored[(*recsize)]==7){board[col7-1][6]=0;col7--;}
    if(player==1&&check==0)
    {player=2;check=1;}
    if(player==2&&check==0)
    {player=1;check=1;}
    
}
void start()
{
   printf("===========================\n");
   printf("  --====||WELCOME|====--\n");
   printf("===========================\n");
    int recsize=0;
    loopchooice(&recsize);
}