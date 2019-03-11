#include <iostream>
#include <vector>

using namespace std;

int getTotalX(vector <int> a, vector <int> b) {
    // Complete this function
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int n = 0;
    
    int init = a[a.size()-1];
    
    for(int i = init; i <= b[0]; i += init){
        bool ok = true;
        
        for(int j = 0; j < a.size()-1 && ok; j++){
            if(i % a[j] != 0)
                ok = false;
        }
        
        for(int j = 0; j < b.size() && ok; j++){
            if(b[j] % i != 0)
                ok = false;            
        }        
        
        if(ok) n++;
    }
    
    return n;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}
