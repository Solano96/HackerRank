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
    int q;
    cin >> n >> q;
    string s;
    cin >> s;

    for(int i = 0; i < q; i++){
        int left, right, tam;
        cin >> left >> right;
        
        vector<string> v;
        
        for(int i = left, tam = right-left+1; i<=right; i++, tam--){
            string str = s.substr(i,tam);
            v.push_back(str);
        }
        
        long long int count = 0;
        string pr;
        
        for (vector<string>::iterator it = v.begin(); it != v.end(); ++it){
            int i = 0; 
            while((pr[i] == (*it)[i])) 
                i++;
            count += (*it).size() - i;
            pr = *it;
        }
        v.clear();
        
        cout << count << endl;
    }
    return 0;
}





