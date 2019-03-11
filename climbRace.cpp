#include <iostream>
#include <vector>

using namespace std;

vector <int> withoutConsecutiveReps(vector<int> v){
    vector<int> s;
    s.push_back(v[0]);
    for(int i = 1; i < v.size(); i++)
        if(v[i]!=v[i-1])
            s.push_back(v[i]);
    return s;
}

vector <int> climbingLeaderboard(vector <int> scores, vector <int> alice) {
    // Complete this function
    vector<int> v = withoutConsecutiveReps(scores);    
    vector<int> solution;
    int ini = v.size()-1;
    
    for(int i = 0; i < alice.size(); i++){
        bool seguir = true;
        for(int j = ini; j >= 0 && seguir; j--){
            if(v[j] >= alice[i]){       
                if(v[j] > alice[i])
                    solution.push_back(j+2);
                if(v[j] == alice[i])
                    solution.push_back(j+1);
                ini = j;
                seguir = false;
            }
            else if(j == 0 && alice[i] > v[j]){
                solution.push_back(1);
                ini = j;              
            }
        }
    }        
    return solution;
}

int main() {
    int n;
    cin >> n;
    vector<int> scores(n);
    for(int scores_i = 0; scores_i < n; scores_i++){
       cin >> scores[scores_i];
    }
    int m;
    cin >> m;
    vector<int> alice(m);
    for(int alice_i = 0; alice_i < m; alice_i++){
       cin >> alice[alice_i];
    }
    vector <int> result = climbingLeaderboard(scores, alice);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;

    system("pause");
}
