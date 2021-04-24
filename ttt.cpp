#include<bits/stdc++.h>
#include "minimax.cpp"

using namespace std;

char players[] = {'O', 'X'};
// char curPlayer, nextPlayer;

void board(char x[3][3]){
    system("CLS");
    for(int i=0; i<3; i++){
        cout << "  "<<x[i][0]<<"   |   "<<x[i][1]<<"   |   "<<x[i][2]<<endl;
        if(i<2) cout << "----------------------\n";
    }
}

bool checkAvail(char x[3][3], int i, int j){
    bool avail = true;
    if(x[i][j] != ' ') avail = false;
    return avail;
}

void Pmove(char (&x)[3][3], int turn){
    int ins,i,j;
    noavail:cout << "Player " << players[turn] << " turn" << endl;
    cin >> ins;
    ins--;
    i = ins/3;
    j = ins%3;
    if(checkAvail(x,i,j)) x[i][j] = players[turn];
    else goto noavail;
}

int main(){
    char ttt[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}, win = ' ';
    int turn;
    board(ttt);
    for(int i=0; i<9; i++){
        turn = i%2;
        Pmove(ttt, turn);
        board(ttt);
        win = checkWin(ttt);
        cout << win << endl;
        if(win != ' ') break;
    }
    board(ttt);
    if(win == 't') cout << "TIE" << endl;
    else cout << players[turn] << " WIN" << endl;
    return 0;
}