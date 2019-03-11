#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

long long mat[100001], m;
int n;

inline long long mode(long long x) {
    if(0<= x && x < m) return x;
    if(m<= x && x < 2LL*m) return x-m;
    if(x < 0) return mode((x%m)+m);
    return x%m;
}


int main() {

    int t = 0;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=0; i<n ; i++) {
            cin >> mat[i];
            mat[i] = mode(mat[i]);
        }
        
        set<long long> s;
        long long acm = 0;
        long long best = 0;
        for(int i=0; i<n; i++) {
            acm = mode(acm + mat[i]);
            best = max(best, acm);

            set<long long>::iterator k = s.upper_bound(acm);
            if(k != s.end()) best = max(best, mode(acm - *k));
            s.insert(acm);
        }
         
        cout << best << endl;
    }
    return 0;
}