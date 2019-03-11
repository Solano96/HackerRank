#include <iostream>
#include <vector>

using namespace std;

vector <int> breakingRecords(vector <int> score) {
    // Complete this function
    int highest, lowest;
    int num_h, num_l;
    highest = lowest = score[0];
    num_h = num_l = 0;
    
    for(int i = 1; i < score.size(); i++){
        if(score[i] > highest){
            highest = score[i];
            num_h++;
        }
        if(score[i] < lowest){
            lowest = score[i];
            num_l++;
        }
    }
    
    vector<int> s(num_h, num_l);
    
    return s;
}

int main() {
    int n;
    cin >> n;
    vector<int> score(n);
    for(int score_i = 0; score_i < n; score_i++){
       cin >> score[score_i];
    }
    vector <int> result = breakingRecords(score);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;


    return 0;
}
