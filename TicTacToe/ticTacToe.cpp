#include <iostream>
#include <algorithm>
using namespace std; 

char squares[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; //where moves stored;  

//Blank board created
void makeBoard(){

    cout << "\n"; 
    cout << "          " << " " << squares[0][0] << " | " << squares[0][1] << " | " << squares[0][2] << "\n"; 
    cout << "          " << "-----------" << "\n";
    cout << "          " << " " << squares[1][0] << " | " << squares[1][1] << " | " << squares[1][2] << "\n"; 
    cout << "          " << "-----------" << "\n";
    cout << "          " << " " << squares[2][0] << " | " << squares[2][1] << " | " << squares[2][2] << "\n"; 
    cout << endl; 

}

//Check to see if a player has won; arg is the player that is currently being checked 
bool checkWinner(int player){

    int r1, r2, r3, c1, c2, c3; 
    int winList[8][3] ={{0,3,6},{1,4,7},{2,5,8},{0,1,2},{3,4,5},{6,7,8},{0,4,8},{2,4,6}}; //all potential win combinations if the top left square is square 0 and bottom right is square 8

    for(int i = 0; i < 8; i++){

        //converting numerical value of potential win pattern to matrix indecies 
        int j = 0;
        r1 = (winList[i][j])/3;
        c1 = (winList[i][j])%3; 
        r2 = (winList[i][j+1])/3;
        c2 = (winList[i][j+1])%3;
        r3 = (winList[i][j+2])/3;
        c3 = (winList[i][j+2])%3;

        //make sure square isn't empty
        if(squares[r1][c1] != ' '){

            //check if all 3 sqaures have same marker
            if(squares[r1][c1] == squares[r2][c2] && squares[r1][c1] == squares[r3][c3] && squares[r3][c3] == squares[r2][c2]){
            cout <<"Player " << player << " wins!"  << endl;
            return true; 
            }
        }  
    }

    return false;

}

void runGame(){  

    bool gameOver = false; //end loop if won
    int p1Move, p2Move, count, rowNum, colNum; //vars for storing numerical input of player moves to matrix index 
    count = 0;  // if 9 rounds tie game 

    while (count < 9){

        cout << "Player one please enter your move: " ; 
        cin >> p1Move; 
        rowNum = p1Move/3; //converting input to row
        colNum = p1Move%3; //converting input to column 
        squares[rowNum][colNum] = 'O'; //placing marker 
        makeBoard();
        gameOver = checkWinner(1); 
        count++; 
        if(count == 9){ cout << "Cats game!" << endl; gameOver = true; } //Tie game 
        if(gameOver == true ){ break; }
        cout << "Player two please enter your move: " ; 
        cin >> p2Move; 
        rowNum = p2Move/3; //converting input to row
        colNum = p2Move%3; //converting input to column
        squares[rowNum][colNum] = 'X'; //placing marker
        makeBoard(); 
        gameOver = checkWinner(2); 
        if(gameOver == true ){ break; }
        count++;     
    }
}

int main(){

    makeBoard(); 
    runGame();
    return 0; 
}
