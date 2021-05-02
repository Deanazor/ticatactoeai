#include<bits/stdc++.h>
// #include "ttt.cpp"

using namespace std;

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

void initScoresX(map<char, int> &scores){
    scores['X'] = 1;
    scores['O'] = -1;
    scores['t'] = 0;
}

void initScoresO(map<char, int> &scores){
    scores['X'] = -1;
    scores['O'] = 1;
    scores['t'] = 0;
}

int minimax(char x[3][3], bool maximizing, char curPlayer, char nextPlayer){
    map<char, int> scores;
    if(curPlayer == 'X') initScoresX(scores);
    else initScoresO(scores);
    
    char win = checkWin(x);
    if(win != ' ') return scores[win];

    if(maximizing){
        int optScore = -9999;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(x[i][j] == ' '){
                    x[i][j] = curPlayer;
                    int score = minimax(x, false, curPlayer, nextPlayer);
                    x[i][j] = ' ';
                    optScore = max(score, optScore);
                }
            }
        }
        return optScore;
    }
    else{
        int optScore = 9999;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(x[i][j] == ' '){
                    x[i][j] = nextPlayer;
                    int score = minimax(x, true, curPlayer, nextPlayer);
                    x[i][j] = ' ';
                    optScore = min(score, optScore);
                }
            }
        }
        return optScore;
    }
}

void Imove(char (&x)[3][3], char curPlayer, char nextPlayer){
    int optScore = -9999;
    vector<int> next(2);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(x[i][j] == ' '){
                x[i][j] = curPlayer;
                int score = minimax(x, false, curPlayer, nextPlayer);
                x[i][j] = ' ';
                if(score > optScore){
                    optScore = score;
                    next[0] = i;
                    next[1] = j;
                }
            }
        }
    }
    x[next[0]][next[1]] = curPlayer;
}