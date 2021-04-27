#include<bits/stdc++.h>
#include "functions.cpp"

using namespace std;

const char players[] = {'O', 'X'};
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

char Play1(char (&x)[3][3]){
    int turn;
    char win;
    board(x);
    for(int i=0; i<9; i++){
        turn = i%2;
        Pmove(x, turn);
        board(x);
        win = checkWin(x);
        cout << win << endl;
        if(win != ' ') break;
    }
    board(x);
    return win;
}

int main(){
    char ttt[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}, win = Play1(ttt);
    if(win == 't') cout << "TIE" << endl;
    else cout << win << " WIN" << endl;
    return 0;
}