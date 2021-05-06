#include<bits/stdc++.h>

using namespace std;

bool checkAvail(char x[3][3], int i, int j){
    bool avail = true;
    if(x[i][j] != ' ') avail = false;
    return avail;
}

bool threeEquals(char a, char b, char c){
    return (a == b) && (b==c) && (a != ' ');
}

bool fullBoard(char x[3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(x[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

char checkWin(char x[3][3]){
    char win = ' ';
    for(int i=0; i<3; i++){
        if(threeEquals(x[i][0], x[i][1], x[i][2])) win = x[i][0];
    }
    for(int i=0; i<3; i++){
        if(threeEquals(x[0][i], x[1][i], x[2][i])) win = x[0][i];
    }

    if(threeEquals(x[0][0], x[1][1], x[2][2])) win = x[0][0];

    if(threeEquals(x[0][2], x[1][1], x[2][0])) win = x[1][1];

    if(fullBoard(x) && win == ' ') win = 't';
    return win;
}

void board(char x[3][3]){
    system("CLS");
    for(int i=0; i<3; i++){
        cout << "  "<<x[i][0]<<"   |   "<<x[i][1]<<"   |   "<<x[i][2]<<endl;
        if(i<2) cout << "----------------------\n";
    }
}