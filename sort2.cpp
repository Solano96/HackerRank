#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
}; 

bool decreasing(Player player1, Player player2){
    return player1.score > player2.score;
}

bool alphabet(Player player1, Player player2){
    return player1.name < player2.name;
}

vector<Player> comparator(vector<Player> players) {
    sort(players.begin(), players.end(), decreasing);
    int v = 0;
    int valor = players[0].score;
    
    for(int i = 0; i < players.size(); i++){
        if(players[i].score != valor){
           sort(players.begin()+v, players.begin()+i, alphabet); 
            v = i;
            valor = players[i].score;
        }
    }
    sort(players.begin()+v, players.end(), alphabet); 
    return players;
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    cout << endl << endl;
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    cin >> n;
}
