#include <iostream>
#include <stdlib.h>
using namespace std;
//Array for the boxes
char boxes[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
//Variable Declaration
int choice;
int row,column;
char turn = 'X';
bool draw = false;

//Function to show the current status of the gaming board

void display_boxes(){

    //Rander Game Board LAYOUT

    cout<<"PLAYER - 1 [X]\t\tPLAYER - 2 [O]\n\n";
    cout<<"\t\t     |     |     \n";
cout<<"\t\t  "<<boxes[0][0]<<"  | "<<boxes[0][1]<<"   | "<<boxes[0][2]<<"\n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<boxes[1][0]<<"  | "<<boxes[1][1]<<"   | "<<boxes[1][2]<<"\n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |      \n";
    cout<<"\t\t  "<<boxes[2][0]<<"  | "<<boxes[2][1]<<"   | "<<boxes[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

//Function to get the player input and update the board

void player_turn(){
    if(turn == 'X'){
        cout<<"\n\tPlayer 1 [X] it's your turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tPlayer 2 [O] it's your turn : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn Start

    cin>> choice;

    //switch case to get which row and column will be update

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout<<"Invalid Move";
    }

    if(turn == 'X' && boxes[row][column] != 'X' && boxes[row][column] != 'O'){
        //updating the position for 'X' symbol if
        //it is not already occupied
        boxes[row][column] = 'X';
        turn = 'O';
    }else if(turn == 'O' && boxes[row][column] != 'X' && boxes[row][column] != 'O'){
        //updating the position for 'O' symbol if
        //it is not already occupied
        boxes[row][column] = 'O';
        turn = 'X';
    }else {
        //if input position already filled
        cout<<"Box already filled!n Please choose another box!!nn";
        player_turn();
    }
    /* Ends */
    display_boxes();
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++)
    if(boxes[i][0] == boxes[i][1] && boxes[i][0] == boxes[i][2] || boxes[0][i] == boxes[1][i] && boxes[0][i] == boxes[2][i])
    return false;

    //checking the win for both diagonal

    if(boxes[0][0] == boxes[1][1] && boxes[0][0] == boxes[2][2] || boxes[0][2] == boxes[1][1] && boxes[0][2] == boxes[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(boxes[i][j] != 'X' && boxes[i][j] != 'O')
    return true;

    //Checking the if game already draw
    draw = true;
    return false;
}

//Program Main Method

int main()
{
    cout<<"\nT I C  -- T A C -- T O E -- G A M E\n";
    cout<<"\nFOR 2 PLAYERS\n";
    while(gameover()){
        display_boxes();
        player_turn();
        gameover();
    }
    if(turn == 'O' && draw == false){
        cout<<"\nPlayer 1 has won the game\n";
    }
    else if(turn == 'X' && draw == false){
        cout<<"\nPlayer 2 has won the game\n";
    }
    else
    cout<<"GAME DRAW!!!";
} 

