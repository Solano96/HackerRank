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
    int len;
    cin >> len;
    string s;
    cin >> s;
    
    bool letras[26] = {false};
    
    for(int i = 0; i < s.size(); i++)
        letras[s[i]-'a'] = true;
    
    vector<char> l;
    
    for(int i = 0; i < 26; i++)
        if(letras[i])
            l.push_back(i+'a');
    
    int max = 0;
    
    for(int i = 0; i < l.size(); i++){
        for(int j = 0; j < l.size(); j++){
            if(i != j){
               string cad = "";
               bool valida = true;
               for(int k = 0; k < s.size() && valida; k++){
                   if(s[k] == l[i])
                      cad += s[k];
                   else if(s[k] == l[j])
                      cad += l[j];
                   if(cad.size() > 1 && cad[cad.size()-1] == cad[cad.size()-2])
                      valida = false;
               }
               if(valida && cad.size() > max)
                   max = cad.size();
            }
        }
    }
    
    cout << max;
    
    return 0;
}
