#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int marcsCakewalk(vector <int> calorie) {
    // Complete this function
    sort(calorie.begin(), calorie.end());
    
    long long int n = 0;
    
    for(int i = calorie.size()-1; i >= 0; i--){
        long long int p = 1;
        for(int j = calorie.size()-1; j > i; j--)
            p*=2;
        n+=p*calorie[i];
    }
    return n;
}

int main() {
    int n;
    cin >> n;
    vector<int> calorie(n);
    for(int calorie_i = 0; calorie_i < n; calorie_i++){
       cin >> calorie[calorie_i];
    }
    long long int result = marcsCakewalk(calorie);
    cout << result << endl;
    char l;
    cin >> l;
}
