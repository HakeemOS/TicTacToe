#include <iostream>
#include <algorithm>
using namespace std; 

char squares[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; //where moves stored 

void makeBoard(){
    cout << "\n"; 
    cout << "          " << " " << squares[0][0] << " | " << squares[0][1] << " | " << squares[0][2] << "\n"; 
    cout << "          " << "-----------" << "\n";
    cout << "          " << " " << squares[1][0] << " | " << squares[1][1] << " | " << squares[1][2] << "\n"; 
    cout << "          " << "-----------" << "\n";
    cout << "          " << " " << squares[2][0] << " | " << squares[2][1] << " | " << squares[2][2] << "\n"; 
    cout << endl; 

}

bool checkWinner(int player){
    int r1, r2, r3, c1, c2, c3; 
    int winList[8][3] ={{0,3,6},{1,4,7},{2,5,8},{0,1,2},{3,4,5},{6,7,8},{0,4,8},{2,4,6}};
    for(int i = 0; i < 9; i++){
        int j = 0;
        r1 = (winList[i][j])/3;
        c1 = (winList[i][j])%3; 
        r2 = (winList[i][j+1])/3;
        c2 = (winList[i][j+1])%3;
        r3 = (winList[i][j+2])/3;
        c3 = (winList[i][j+2])%3;
        if(squares[r1][c1] != ' '){
            if(squares[r1][c1] == squares[r2][c2] && squares[r1][c1] == squares[r3][c3]){
            cout <<"Player " << player << " wins!"  << endl;
            return true; 
            }
        }
        
        
    }

    return false;

}

void runGame(){
    
    bool gameOver = false; 
    int p1Move, p2Move, count, rowNum, colNum; 
    count = 0;  
    int winList[8][3] ={{0,3,6},{1,4,7},{2,5,8},{0,1,2},{3,4,5},{6,7,8},{0,4,8},{2,4,6}}; 
    int p1List[3] = {0,0,0};
    int p1TempList[3] = {0,0,0};
    int p2List[3] = {0,0,0}; 

    while (count < 9){
        cout << "Player one please enter your move: " ; 
        cin >> p1Move; 
        rowNum = p1Move/3; 
        colNum = p1Move%3; 
        squares[rowNum][colNum] = 'O'; 
        makeBoard(); 
        gameOver = checkWinner(1); 
        count++;
        if(count == 9){ gameOver = true; }
        if(gameOver == true ){ break; }
        cout << "Player two please enter your move: " ; 
        cin >> p2Move; 
        rowNum = p2Move/3; 
        colNum = p2Move%3; 
        squares[rowNum][colNum] = 'X'; 
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
