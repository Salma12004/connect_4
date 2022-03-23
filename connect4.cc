// connect 4 game 
//  2 players play by putting sympols in the board 
// the one who connect 4 same sympol first win 
// Author: Salma Mohammed Mahmoud
// Date: 3/3/2022
// Version:1.0

#include<iostream>
#include<list>
using namespace std;

char board[6][7]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
// we can not print the list in the its shape so we make a function to print it in the shape we want
void create_board(){
    for (int i=0; i<6; i++){
        for (int j=0; j<7; j++){
            if (j==0){// to put [ before the list
                cout<<"[";
            }
            cout<<board[i][j];
            if (i<6 and j<6){
                cout<<" ,";//to put , between element in the list
            }
            if (j==6){
                cout<<"]"<<endl;//to put ] after the list
            }
        }
    }cout<<endl;
} 

bool horizontal_winning(char playersympol){// function to check horizontal winning 
    int i=0;
    for (int row=5; row>=0;row--){// to loop in each row in the board in reverse order
        for (int element=0; element<7; element++){// to loop in each element in the row
            if (board[row][element]==playersympol){
                i+=1;
                if (i==4){// if he connect 4 same sympol return true
                    return true;
                }
            }
            else{
                i=0;//to loop from the first
            }
        }
    }
    return false;
}

bool vertical_winning(char playersympol){//function to check vertical winning
    int i=0;
    for (int column=0; column<7; column++){// to loop in each column
        for (int row=0; row<6; row++){//to loop in each row 
            if (board[row][column]==playersympol){
                i+=1;
                if (i==4){// if he connect 4 same sympol return true
                    return true;
                }
            }
            else{
                i=0;//to loop from the first
            }
        }
    }
    return false;
}

bool diagonal_winning(char playersympol){// function to check diagonal winning
    int columns,rows;//declare rows and columns 
    columns=7;
    rows=6;
    for (int i=0; i<columns-3; i++){//to loop from 0 to 4
        for (int j=0; j<rows-3; j++){//to loop from 0 to 3
            if (board[j][i]==playersympol and board[j+1][i+1]==playersympol and board[j+2][i+2]==playersympol and board[j+3][i+3]==playersympol){
                return true;// if he connect 4 same sympol return true
            }
        }
    }
    for (int i=0; i<columns-3; i++){//to loop from 0 to 4
        for (int j=3; j<rows; j++){//to loop from 3 to 6
            if (board[j][i]==playersympol and board[j-1][i+1]==playersympol and board[j-2][i+2]==playersympol and board[j-3][i+3]==playersympol){
                return true;// if he connect 4 same sympol return true
            }
        }
    }
    return false;
}

bool iswinner(char playersympol){// if heconnect 4 sympol in vertical or horizontal or diagonal return true
    if (horizontal_winning(playersympol) or vertical_winning(playersympol) or diagonal_winning(playersympol)){
        return true;
    }
    return false;
}

int main(){
    
   int columns,rows,choosesympol;// declare sum variable 
   char player1sympol,player2sympol;
   columns=7;
   rows=6;
   create_board();//call the board function 

   int list2[7]={1,2,3,4,5,6,7};//the 7 columns

   char list1[2]={'X','O'};
   //to print the list in its shape 
   for(int i=0; i<2; i++){
       if (i==0){
           cout<<"[";
       }
       cout<<list1[i];
       if (i<1){
           cout<<",";
       }
       if(i==1){
           cout<<"]";
       }
   }cout<<endl;
   //print list 1 to make sure that each player know the available sympols
   cout<<"pls player1 choose index 0 or 1 ";
   cin>>choosesympol;
   if(choosesympol==0){//to make player1 choose x or o
       player1sympol='X';
       player2sympol='O';
   }
   else{
       player2sympol='X';
       player1sympol='O';
   }  
   cout<<"player1 sympol is "<<player1sympol<<endl;//to tell each player his sympol 
   cout<<"player2 sympol is "<<player2sympol<<endl;

   for(int i=0; i<42; i++){//all avalabile places in the board
       if (i%2==0){//to switch turns between player1 and player2
              for (int i=0; i<7; i++){
                cout<<" "<<list2[i]<<" ";//to print the numbers of columns
              }
              cout<<endl; 
              create_board();//call board function
              int p1; 
              cout<<"pls player1 choose column you want to play in ";
              cin>>p1;//take from player1 the column he want to play in and put it in p1
              for (int row=5; row>=0; row--){//to loop in each row in reverse
                  if (board[row][p1-1]==' '){//[p1-1] because when he choose column 1 that means column 0 in the list
                      board[row][p1-1]=player1sympol;//put the sympol in the place he want
                      break;//to make player2 play
                  }      
              }
              create_board();// call board function
              if (iswinner(player1sympol)){//if iswinner() return true that means he win 
                  cout<<"PLAYER 1 WINNNNNNN"<<endl;
                  break;//to end the game 
              }
       }
       else{
           for (int i=0; i<7; i++){
               cout<<" "<<list2[i]<<" ";//to print the numbers of columns
           }
           cout<<endl;
           create_board();//call board function
           int p2;
           cout<<"pls player2 choose column you want to play in ";
           cin>>p2;//take from player2 the column he want to play in and put it in p2
           for (int row=5; row>=0; row--){//to loop in each row in reverse
               if (board[row][p2-1]==' '){//[p2-1] because when he choose column 1 that means column 0 in the list
                   board[row][p2-1]=player2sympol;//put the sympol in the place he want
                   break;//to make player1 play
               }
           }
           create_board();// call board function
           if (iswinner(player2sympol)){//if iswinner() return true that means he win
               cout<<"PLAYER 2 WINNNNNNNN"<<endl;
               break;//to end the game
           }
       } 
   }
}
