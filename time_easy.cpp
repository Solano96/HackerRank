#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int n;
    int k;
    int q;
    cin >> n >> k >> q;
    vector<int> a(n);
    vector<int> index(q);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    for(int a0 = 0; a0 < q; a0++){        
        cin >> index[a0];
    }
    for(int a0 = 0; a0 < q; a0++){   
        int i =  index[a0]-k)%n;
        if(i < 0) i+=n;
        cout << a[i] << endl;
    }
    cin >> n;
    return 0;
}

