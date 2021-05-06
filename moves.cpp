#include<bits/stdc++.h>
#include "base.cpp"

using namespace std;
const char players[] = {'O', 'X'};

void Pmove(char x[3][3], int turn){
    int ins,i,j;
    noavail:
    cout << "Player " << players[turn] << " turn" << endl;
    cin >> ins;
    ins--;
    i = ins/3;
    j = ins%3;
    if(checkAvail(x,i,j)) x[i][j] = players[turn];
    else goto noavail;
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

void Imove(char x[3][3], char curPlayer, char nextPlayer){
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