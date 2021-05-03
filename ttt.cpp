#include<bits/stdc++.h>
#include<windows.h>
#include "functions.cpp"

using namespace std;

void board(char x[3][3]){
    system("CLS");
    for(int i=0; i<3; i++){
        cout << "  "<<x[i][0]<<"   |   "<<x[i][1]<<"   |   "<<x[i][2]<<endl;
        if(i<2) cout << "----------------------\n";
    }
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

char Play2(char x[3][3]){
    int pchoice, turn;
    re:
    cout << "Choose palyer\n1. O\n2. X\nYour choice? ";
    cin >> pchoice;
    --pchoice;
    if(pchoice>1 || pchoice<0) goto re;
    char human = players[pchoice], bot = players[(int) pchoice == 0], win;
    board(x);
    for(int i=0; i<9; i++){
        turn = i%2;
        if(turn == pchoice) Pmove(x, turn);
        else {
            Imove(x, bot, human);
            Sleep(200);
        }
        board(x);
        win = checkWin(x);
        cout << win << endl;
        if(win != ' ') break;
    }
    board(x);
    return win;
}

int main(){
    char ttt[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}, win;
    int mode;
    re_mode:
    cout << "Which game mode?\n1. vs human\n2. vs AI\nYour choice? ";
    cin >> mode;
    switch (mode)
    {
    case 1:
        win = Play1(ttt);
        break;
    case 2:
        win = Play2(ttt);
        break;
    default:
        goto re_mode;
        break;
    }
    if(win == 't') cout << "TIE" << endl;
    else cout << win << " WIN" << endl;
    return 0;
}